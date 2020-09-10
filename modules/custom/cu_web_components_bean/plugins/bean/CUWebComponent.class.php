<?php

/**
 * @file
 * WC Bean.
 */
class CUWebComponent extends BeanPlugin {
  
  /**
   * Declares default block settings. values must match the form ids or they wont save
   */
  public function values() {
    $values = [
        'wc_name' => '',
        'wc_data_option' => '',
        'resource_id' => ''
    ];
    return array_merge(parent::values(), $values);
  }
  

  
  /**
   * Builds extra settings for the block edit form.
   */
  public function form($bean, $form, &$form_state) {
    $form = [];
    $default = $this->getDefaultConfig($bean);

    $form['wc_name'] = [
      '#type' => 'textfield',
      '#title' => 'Web Component',
      '#description' => 'Select the web component you want displayed',
      '#autocomplete_path' => 'taxonomy/autocomplete/field_web_component',
      '#default_value' => $bean->wc_name,
      '#maxlength' => 1024,
      '#ajax' => array(
          'callback' => 'ajax_wc_data_options_callback',
          'wrapper' => 'checkboxes-div',
          'method' => 'replace',
          'effect' => 'fade',
      ),
      
    ];
    
    // the content of this fieldset will change baased on the WC selected
    $form['data_options'] = [
        '#type' => 'fieldset',
        '#title' => 'Dataset Options',
        '#description' => $default['desc'],
        '#prefix' => '<div id="checkboxes-div">',
        '#suffix' => '</div>',
    ];
    
    $form['data_options']['wc_data_option'] = [
       '#type' => 'select',
       '#options' => $default['options'],
       '#title' => t('Data Source Option'),
       '#validated' => true, //prevent drupal from throwing an error from creating dynamic options
    ];
    
    $form['resource_id'] = [
        '#type' => 'textfield',
        '#title' => 'Resource ID',
        '#default_value' => $bean->resource_id,
        '#description' => 'The ID of the data that you want to get'
    ];
    
    return $form;
  }
  

  
  // set default options if the user is editing a bean
  // @return {array} returns the proper default description and options array
  public function getDefaultConfig($bean){
        $default = [
            'options' => ['default' => '-- WC Data Options --'],
            'desc' => 'Some api endpoints can return data on more than one subject. Please select the Web component you want to show first.'
        ];
        if(!empty($bean->wc_name)){
            $vocabulary = taxonomy_vocabulary_machine_name_load('web_component_data_options');
            $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vocabulary->vid));
            $arr =[];
            foreach($terms as $i){
                $wc = taxonomy_term_load(($i->field_web_component)['und'][0]['tid']);
                if($wc->name === $default){
                    $arr[$i->tid] = $i->name;
                }
            }
            if(count($arr) > 0){
                $default['options'] = $arr;
                $default['desc'] = 'Please select what data you want to show from this data source';
            }
            else{
                $default['desc'] = 'There are no data options for this web component';
            }
        }
        return $default;
  }

  /**
   * Displays the bean.
   */
  public function view($bean, $content, $view_mode = 'default', $langcode = NULL) {
    $wc_name = $url = '';
    $vid = taxonomy_vocabulary_machine_name_load('web_components')->vid;
    $terms = entity_load('taxonomy_term', FALSE, array('vid' => $vid));
    foreach($terms as $i){
        if($i->name === $bean->wc_name){
            $wc_name = $i->field_wc_name['und'][0]['value'];
            $url = $i->field_api_endpoint['und'][0]['value'];
            break;
        }
    }
    
    $content['#theme'] = 'bean__cu_web_components_bean';
    $content['#wc_name'] = $wc_name;
    $content['#resource_id'] = $bean->resource_id;
    $content['#api_endpoint'] = str_replace('[id]', $bean->resource_id, $url);
    $content['#wc_data_option'] = !$bean->wc_data_option ? null : taxonomy_term_load($bean->wc_data_option)->name;

    return $content;
  }
}