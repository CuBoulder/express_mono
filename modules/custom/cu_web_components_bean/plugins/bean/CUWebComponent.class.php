<?php

/**
 * @file
 * WC Bean.
 */
class CUWebComponent extends BeanPlugin {
    private $components, $data_options;
  
  /**
   * Declares default block settings. values must match the form ids or they wont save
   */
  public function values() {
    $values = [
        'wc_name' => '',
        'wc_data_option' => '',
        'resource_id' => '',
        'api_endpoint' => ''
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
      '#type' => 'radios',
      '#title' => 'Web Component',
      '#args' => $this->data_options,
      '#default_value' => $bean->wc_name,
      '#description' => 'Select the web component you want displayed',
      '#options' => $this->components,
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
       '#default_value' => $bean->wc_data_option,
       '#validated' => true, //prevent drupal from throwing an error from creating dynamic options
    ];
    
    $form['data_options']['api_endpoint'] = [
        '#type' => 'hidden',
        '#default_value' =>$bean->api_endpoint
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
    $res = drupal_http_request('https://spreadsheets.google.com/feeds/list/1wj5ZwMhf3D-KN_LGjweCEhvCEW0wTp3u-Wz4SzBAtRo/1/public/values?alt=json');
    if($res->code !== '200'){
        drupal_set_message(t('Could not retrieve available Web Components. Please contact your site admin.'), 'error');
        $this->components = [];
    }
    else{
        $res = json_decode($res->data, true);
        foreach($res['feed']['entry'] as $i){
            $this->components[$i['gsx$webcomponentname']['$t']] = $i['gsx$webcomponentlabel']['$t'];
            $this->data_options[$i['gsx$webcomponentname']['$t']] = ['options' => $i['gsx$dataoptions']['$t'], 'api_endpoint' => $i['gsx$apiendpoint']['$t'] ];
        };
    }
    $default = [
        'options' => ['default' => '-- WC Data Options --'],
        'desc' => 'Some api endpoints can return data on more than one subject. Please select the Web component you want to show first.'
    ];
    if(!empty($bean->wc_name)){
        $options = []; 
        $arr = [];
        foreach($this->data_options as $key => $i){
            if($key == $bean->wc_name && $i['options'] !== 'none'){
                $arr = explode(', ', $i['options']);
                break;
            }
        }
        if(count($arr) > 0){
            foreach($arr as $key => $i){
                $options[$i] = $i;
            }
            $default['options'] = $options;
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
    $content['#theme'] = 'bean__cu_web_components_bean';
    $content['#wc_name'] = $bean->wc_name;
    $content['#resource_id'] = $bean->resource_id;
    $content['#api_endpoint'] = str_replace('[id]', $bean->resource_id, $bean->api_endpoint);
    $content['#wc_data_option'] = $bean->wc_data_option;

    return $content;
  }
}