<?php
/**
 * @file
 * Context plugin file to provide changing the active theme as a context
 * reaction.
 */

/**
 * Expose themes as context reactions.
 */
class context_reaction_embed_chat_widget extends context_reaction {

  /**
   * Grab the available themes and provide them as a reaction for context.
   *
   * @param $context
   *   The context as passed from context module.
   *
   * @return array
   *   The FAPI array as read by context module.
   */
  function options_form($context) {

    $settings = $this->fetch_from_context($context);
    $filter = array(
      'admithub',
      'livechat',
    );
    $embeds = cu_js_includes_get_includes_by_type($filter);
    $options = array();
    foreach ($embeds as $key => $embed) {
      $options[$key] = $embed->name;
    }
    $form = array(
      '#tree' => TRUE,
      '#title' => t('Embed Chat Widget'),
      'chat_widget_embed' => array(
        '#title' => t('Chat Widget Embeds'),
        '#description' => t('Choose one of the available chat widgets.'),
        '#type' => 'select',
        '#default_value' => isset($settings['chat_widget_embed']) ? $settings['chat_widget_embed'] : '',
        '#options' => $options,
      ),
    );
    return $form;
  }

  /**
   * Return the active theme based on the context
   *
   * @return string | null
   *   String of the theme name, or NULL if not to be altered.
   */
  function execute() {
    $embed_chat_widget = NULL;
    foreach ($this->get_contexts() as $context) {
      if (isset($context->reactions['embed_chat_widget'])) {
        $embed_chat_widget = $context->reactions['embed_chat_widget'];
      }
    }
    return $embed_chat_widget;
  }

}
