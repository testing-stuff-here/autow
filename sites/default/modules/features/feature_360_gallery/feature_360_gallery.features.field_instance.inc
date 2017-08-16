<?php
/**
 * @file
 * feature_360_gallery.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function feature_360_gallery_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'field_collection_item-field_360_images-field_360_fc_large'
  $field_instances['field_collection_item-field_360_images-field_360_fc_large'] = array(
    'bundle' => 'field_360_images',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_360_fc_large',
    'label' => 'Large Image',
    'required' => FALSE,
    'settings' => array(
      'alt_field' => 0,
      'alt_field_required' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'title_field_required' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_360_images-field_360_fc_nav'
  $field_instances['field_collection_item-field_360_images-field_360_fc_nav'] = array(
    'bundle' => 'field_360_images',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_360_fc_nav',
    'label' => 'Navigator Image',
    'required' => FALSE,
    'settings' => array(
      'alt_field' => 0,
      'alt_field_required' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'title_field_required' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 33,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_360_images-field_360_fc_small'
  $field_instances['field_collection_item-field_360_images-field_360_fc_small'] = array(
    'bundle' => 'field_360_images',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_360_fc_small',
    'label' => 'Small Image',
    'required' => FALSE,
    'settings' => array(
      'alt_field' => 0,
      'alt_field_required' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'title_field_required' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 32,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_360_images-field_360_fc_x'
  $field_instances['field_collection_item-field_360_images-field_360_fc_x'] = array(
    'bundle' => 'field_360_images',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_360_fc_x',
    'label' => 'X Coordinate',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 34,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_360_images-field_360_fc_y'
  $field_instances['field_collection_item-field_360_images-field_360_fc_y'] = array(
    'bundle' => 'field_360_images',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_360_fc_y',
    'label' => 'Y Coordinate',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 35,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_additional_leadworks_ids'
  $field_instances['field_collection_item-field_pop_up_registration-field_additional_leadworks_ids'] = array(
    'bundle' => 'field_pop_up_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_additional_leadworks_ids',
    'label' => 'Additional Leadworks IDs',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => 0,
    ),
    'weight' => 6,
    'widget' => array(
      'active' => 1,
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_purf_hide_spop_mailing'
  $field_instances['field_collection_item-field_pop_up_registration-field_purf_hide_spop_mailing'] = array(
    'bundle' => 'field_pop_up_registration',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_purf_hide_spop_mailing',
    'label' => 'Don\'t display PURF for anyone who clicks through from a Silverpop mailing',
    'required' => 0,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_onoff',
      'weight' => 40,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_smg_pop_ad_id'
  $field_instances['field_collection_item-field_pop_up_registration-field_smg_pop_ad_id'] = array(
    'bundle' => 'field_pop_up_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_smg_pop_ad_id',
    'label' => 'Ad Leadworks ID',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 35,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_smg_pop_data'
  $field_instances['field_collection_item-field_pop_up_registration-field_smg_pop_data'] = array(
    'bundle' => 'field_pop_up_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_smg_pop_data',
    'label' => 'field_smg_pop_data',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 38,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_smg_pop_exp_date'
  $field_instances['field_collection_item-field_pop_up_registration-field_smg_pop_exp_date'] = array(
    'bundle' => 'field_pop_up_registration',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_smg_pop_exp_date',
    'label' => 'Campaign Expiration Date',
    'required' => FALSE,
    'settings' => array(
      'default_value' => 'blank',
      'default_value2' => 'blank',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 1,
        'input_format' => 'm/d/Y',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '0:+3',
      ),
      'type' => 'date_popup',
      'weight' => 39,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_smg_pop_headline_exist_usr'
  $field_instances['field_collection_item-field_pop_up_registration-field_smg_pop_headline_exist_usr'] = array(
    'bundle' => 'field_pop_up_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_smg_pop_headline_exist_usr',
    'label' => 'Headline for Existing Users',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 32,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_smg_pop_headline_new_usr'
  $field_instances['field_collection_item-field_pop_up_registration-field_smg_pop_headline_new_usr'] = array(
    'bundle' => 'field_pop_up_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_smg_pop_headline_new_usr',
    'label' => 'Headline for New Users',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 31,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_smg_pop_leadworks_id'
  $field_instances['field_collection_item-field_pop_up_registration-field_smg_pop_leadworks_id'] = array(
    'bundle' => 'field_pop_up_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_smg_pop_leadworks_id',
    'label' => 'Master Leadworks ID',
    'required' => FALSE,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'number',
      'settings' => array(),
      'type' => 'number',
      'weight' => 34,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_smg_pop_registration_form'
  $field_instances['field_collection_item-field_pop_up_registration-field_smg_pop_registration_form'] = array(
    'bundle' => 'field_pop_up_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_smg_pop_registration_form',
    'label' => 'Registration Form',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 33,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_smg_pop_source_code'
  $field_instances['field_collection_item-field_pop_up_registration-field_smg_pop_source_code'] = array(
    'bundle' => 'field_pop_up_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'This value will be appended to the CRM Lead Source and History Slug fields in Silverpop',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_smg_pop_source_code',
    'label' => 'Source Code',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 37,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_smg_pop_submit_text'
  $field_instances['field_collection_item-field_pop_up_registration-field_smg_pop_submit_text'] = array(
    'bundle' => 'field_pop_up_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_smg_pop_submit_text',
    'label' => 'Text for Submit Button',
    'required' => FALSE,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 36,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_pop_up_registration-field_smg_pop_type'
  $field_instances['field_collection_item-field_pop_up_registration-field_smg_pop_type'] = array(
    'bundle' => 'field_pop_up_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Specify how this pop-up will load, either automatically on page-load, or based on the user\'s action (clicking video or inline link).',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'field_name' => 'field_smg_pop_type',
    'label' => 'Type of Pop-Up',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'weight' => 0,
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 0,
    ),
  );

  // Exported field_instance: 'node-360_package_spin_rotate-body'
  $field_instances['node-360_package_spin_rotate-body'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'body',
    'label' => 'Body',
    'required' => FALSE,
    'settings' => array(
      'display_summary' => TRUE,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-360_package_spin_rotate-field_360_images'
  $field_instances['node-360_package_spin_rotate-field_360_images'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 14,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_360_images',
    'label' => '360 Images',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 19,
    ),
  );

  // Exported field_instance:
  // 'node-360_package_spin_rotate-field_360_images_reverse'
  $field_instances['node-360_package_spin_rotate-field_360_images_reverse'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 8,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_360_images_reverse',
    'label' => 'Reverse Order of 360 Images',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 20,
    ),
  );

  // Exported field_instance:
  // 'node-360_package_spin_rotate-field_360_magic_plugin'
  $field_instances['node-360_package_spin_rotate-field_360_magic_plugin'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_360_magic_plugin',
    'label' => '360 Magic plugin',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'options_onoff',
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'node-360_package_spin_rotate-field_360_magic_plugin_columns'
  $field_instances['node-360_package_spin_rotate-field_360_magic_plugin_columns'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A multiple-column spin, which can rotate images left/right. Fill this field if plugin360 will be used in this node.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 15,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_360_magic_plugin_columns',
    'label' => '360 magic plugin columns',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'number',
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'node-360_package_spin_rotate-field_360_magic_plugin_rows'
  $field_instances['node-360_package_spin_rotate-field_360_magic_plugin_rows'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'A multiple-row spin, which can rotate images up/down. Fill this field if plugin360 will be used in this node.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 12,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_360_magic_plugin_rows',
    'label' => '360 magic plugin rows',
    'required' => 0,
    'settings' => array(
      'max' => '',
      'min' => '',
      'prefix' => '',
      'suffix' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'number',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'number',
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'node-360_package_spin_rotate-field_360_multi_upload'
  $field_instances['node-360_package_spin_rotate-field_360_multi_upload'] = array(
    'bundle' => '360_package_spin_rotate',
    'deleted' => 0,
    'description' => 'Please upload all of the <strong>LARGE IMAGES</strong> that were provided for this 360.  This is a multi-upload field, so select ALL of the files at once',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 13,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_360_multi_upload',
    'label' => 'Upload Images for 360 Gallery',
    'required' => FALSE,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '360_gallery',
      'file_extensions' => 'txt jpg png gif jpeg',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'module' => 'multiupload_filefield_widget',
      'settings' => array(
        'allowed_schemes' => array(
          0 => 'public',
          1 => 'private',
        ),
        'allowed_types' => array(
          0 => 'image',
        ),
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_mfw',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-360_package_spin_rotate-field_allterms'
  $field_instances['node-360_package_spin_rotate-field_allterms'] = array(
    'bundle' => '360_package_spin_rotate',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'reltw',
        'settings' => array(),
        'type' => 'reltw_default',
        'weight' => 7,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 6,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_allterms',
    'label' => 'Terms',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
      'vids' => array(
        1 => 0,
        2 => 0,
        3 => 3,
        4 => 4,
        5 => 0,
        7 => 0,
        8 => 0,
        9 => 0,
        10 => 0,
        11 => 0,
        12 => 0,
        13 => 13,
        14 => 14,
      ),
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'reltw',
      'settings' => array(),
      'type' => 'reltw_widget',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'node-360_package_spin_rotate-field_companies'
  $field_instances['node-360_package_spin_rotate-field_companies'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 6,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 5,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_companies',
    'label' => 'Companies',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-360_package_spin_rotate-field_deckhead'
  $field_instances['node-360_package_spin_rotate-field_deckhead'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 2,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_deckhead',
    'label' => 'Deckhead',
    'required' => 1,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'node-360_package_spin_rotate-field_gallery_360_field_location'
  $field_instances['node-360_package_spin_rotate-field_gallery_360_field_location'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '<ol>
  <li>Upload 360 Gallery via File browser</li>
  <li>Copy and Paste in the folder name</li>
</ol>',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gallery_360_field_location',
    'label' => '360 Gallery Folder Location',
    'required' => 0,
    'settings' => array(
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'node-360_package_spin_rotate-field_image'
  $field_instances['node-360_package_spin_rotate-field_image'] = array(
    'bundle' => '360_package_spin_rotate',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 10,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => 'content',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'alt_field_required' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'title_field_required' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'node-360_package_spin_rotate-field_pop_up_registration'
  $field_instances['node-360_package_spin_rotate-field_pop_up_registration'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 11,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pop_up_registration',
    'label' => 'Pop Up Registration',
    'required' => FALSE,
    'settings' => array(
      'user_register_form' => 0,
    ),
    'widget' => array(
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-360_package_spin_rotate-field_related'
  $field_instances['node-360_package_spin_rotate-field_related'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 3,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 7,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_related',
    'label' => 'Related content',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'node_reference',
      'settings' => array(
        'autocomplete_match' => 'contains',
        'autocomplete_path' => 'node_reference/autocomplete',
        'size' => 60,
      ),
      'type' => 'node_reference_autocomplete',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-360_package_spin_rotate-field_term_coverage'
  $field_instances['node-360_package_spin_rotate-field_term_coverage'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 4,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_term_coverage',
    'label' => 'Coverage type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-360_package_spin_rotate-field_term_source_type'
  $field_instances['node-360_package_spin_rotate-field_term_source_type'] = array(
    'bundle' => '360_package_spin_rotate',
    'default_value' => array(
      0 => array(
        'tid' => 138,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 5,
      ),
      'jquerymobile_teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_term_source_type',
    'label' => 'Source Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('360 Gallery Folder Location');
  t('360 Images');
  t('360 Magic plugin');
  t('360 magic plugin columns');
  t('360 magic plugin rows');
  t('<ol>
  <li>Upload 360 Gallery via File browser</li>
  <li>Copy and Paste in the folder name</li>
</ol>');
  t('A multiple-column spin, which can rotate images left/right. Fill this field if plugin360 will be used in this node.');
  t('A multiple-row spin, which can rotate images up/down. Fill this field if plugin360 will be used in this node.');
  t('Ad Leadworks ID');
  t('Additional Leadworks IDs');
  t('Body');
  t('Campaign Expiration Date');
  t('Companies');
  t('Coverage type');
  t('Deckhead');
  t('Don\'t display PURF for anyone who clicks through from a Silverpop mailing');
  t('Headline for Existing Users');
  t('Headline for New Users');
  t('Image');
  t('Large Image');
  t('Master Leadworks ID');
  t('Navigator Image');
  t('Please upload all of the <strong>LARGE IMAGES</strong> that were provided for this 360.  This is a multi-upload field, so select ALL of the files at once');
  t('Pop Up Registration');
  t('Registration Form');
  t('Related content');
  t('Reverse Order of 360 Images');
  t('Small Image');
  t('Source Code');
  t('Source Type');
  t('Specify how this pop-up will load, either automatically on page-load, or based on the user\'s action (clicking video or inline link).');
  t('Terms');
  t('Text for Submit Button');
  t('This value will be appended to the CRM Lead Source and History Slug fields in Silverpop');
  t('Type of Pop-Up');
  t('Upload Images for 360 Gallery');
  t('X Coordinate');
  t('Y Coordinate');
  t('field_smg_pop_data');

  return $field_instances;
}
