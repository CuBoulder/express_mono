<?php

/**
 * Form values for Facebook tracking pixel.
 *
 * @param array $form
 *   Form containing default embed template form options.
 * @param array $form_state
 *   State of the default embed template form.
 * @param int|null $id
 *   ID of the current embed being edited if that embed exists.
 * @param array $data
 *   Data of the current embed if it is being edited.
 */
function cu_js_includes_admithub_form(&$form, &$form_state, $id = NULL, $data = array()) {
  $form['options']['account_id'] = array(
    '#title' => t('License ID'),
    '#type' => 'textfield',
    '#default_value' => !empty($data['account_id']) ? $data['account_id'] : '',
    '#required' => TRUE,
    '#size' => 128,
  );
}

 /**
  * Form values for Facebook tracking pixel.
  *
  * @param array $form
  *   Form containing default embed template form options.
  * @param array $form_state
  *   State of the default embed template form.
  * @param int|null $id
  *   ID of the current embed being edited if that embed exists.
  * @param array $data
  *   Data of the current embed if it is being edited.
  */
function cu_js_includes_livechat_form(&$form, &$form_state, $id = NULL, $data = array()) {
  $form['options']['account_id'] = array(
    '#title' => t('License ID'),
    '#type' => 'textfield',
    '#default_value' => !empty($data['account_id']) ? $data['account_id'] : '',
    '#required' => TRUE,
    '#size' => 128,
  );
}

function cu_js_includes_statuspage_form(&$form, &$form_state, $id = NULL, $data = array()) {
  $form['options']['statuspage_url'] = array(
    '#title' => t('StatusPage.io URL'),
    '#type' => 'textfield',
    '#default_value' => !empty($data['statuspage_url']) ? $data['statuspage_url'] : '',
    '#required' => TRUE,
    '#size' => 128,
  );
}

function cu_js_includes_slateform_form(&$form, &$form_state, $id = NULL, $data = array()) {
  $form['options']['slate_form_id'] = array(
    '#title' => t('Form ID'),
    '#type' => 'textfield',
    '#default_value' => !empty($data['slate_form_id']) ? $data['slate_form_id'] : '',
    '#required' => TRUE,
    '#size' => 128,
  );

  $form['options']['slate_domain'] = array(
    '#title' => t('Slate Domain'),
    '#type' => 'textfield',
    '#default_value' => !empty($data['slate_domain']) ? $data['slate_domain'] : '',
    '#required' => TRUE,
    '#size' => 128,
  );
}
