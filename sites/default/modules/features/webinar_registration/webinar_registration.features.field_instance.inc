<?php
/**
 * @file
 * webinar_registration.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function webinar_registration_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-webinar_registration-body'
  $field_instances['node-webinar_registration-body'] = array(
    'bundle' => 'webinar_registration',
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
      'teaser' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(
          'field_injector_field' => '',
          'field_injector_position' => '',
          'trim_length' => 600,
        ),
        'type' => 'text_summary_or_trimmed',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
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
      'weight' => 11,
    ),
  );

  // Exported field_instance:
  // 'node-webinar_registration-field_accelaworks_billcode'
  $field_instances['node-webinar_registration-field_accelaworks_billcode'] = array(
    'bundle' => 'webinar_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 5,
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
    'field_name' => 'field_accelaworks_billcode',
    'label' => 'AccelaWorks Billcode',
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
      'settings' => array(),
      'type' => 'number',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'node-webinar_registration-field_allterms'
  $field_instances['node-webinar_registration-field_allterms'] = array(
    'bundle' => 'webinar_registration',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'reltw',
        'settings' => array(),
        'type' => 'reltw_default',
        'weight' => 17,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'module' => 'reltw',
        'settings' => array(),
        'type' => 'reltw_default',
        'weight' => 17,
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
        11 => 11,
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
      'weight' => 14,
    ),
  );

  // Exported field_instance: 'node-webinar_registration-field_companies'
  $field_instances['node-webinar_registration-field_companies'] = array(
    'bundle' => 'webinar_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 16,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'module' => 'node_reference',
        'settings' => array(),
        'type' => 'node_reference_default',
        'weight' => 16,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_companies',
    'label' => 'Company',
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
      'weight' => 13,
    ),
  );

  // Exported field_instance: 'node-webinar_registration-field_content_pdf'
  $field_instances['node-webinar_registration-field_content_pdf'] = array(
    'bundle' => 'webinar_registration',
    'deleted' => 0,
    'description' => 'Upload the content to be delivered after registration',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
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
        'module' => 'file',
        'settings' => array(),
        'type' => 'file_default',
        'weight' => 12,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_content_pdf',
    'label' => 'Content PDF',
    'required' => 0,
    'settings' => array(
      'description_field' => 0,
      'file_directory' => '',
      'file_extensions' => 'pdf',
      'max_filesize' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'file',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'file_generic',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'node-webinar_registration-field_disclaimer'
  $field_instances['node-webinar_registration-field_disclaimer'] = array(
    'bundle' => 'webinar_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_disclaimer',
    'label' => 'Disclaimer',
    'required' => 0,
    'settings' => array(
      'display_summary' => 0,
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 20,
        'summary_rows' => 5,
      ),
      'type' => 'text_textarea_with_summary',
      'weight' => 12,
    ),
  );

  // Exported field_instance: 'node-webinar_registration-field_expert'
  $field_instances['node-webinar_registration-field_expert'] = array(
    'bundle' => 'webinar_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 6,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'add' => 'Add',
          'delete' => 'Delete',
          'description' => TRUE,
          'edit' => 'Edit',
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_view',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_expert',
    'label' => 'Speaker',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'node-webinar_registration-field_form_header'
  $field_instances['node-webinar_registration-field_form_header'] = array(
    'bundle' => 'webinar_registration',
    'default_value' => array(
      0 => array(
        'value' => 'Fill out the form below to register for this webinar!',
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 14,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_form_header',
    'label' => 'Form header',
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
      'weight' => 17,
    ),
  );

  // Exported field_instance:
  // 'node-webinar_registration-field_gotowebinar_webinar_date'
  $field_instances['node-webinar_registration-field_gotowebinar_webinar_date'] = array(
    'bundle' => 'webinar_registration',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'custom',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
        ),
        'type' => 'date_default',
        'weight' => 2,
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
    'field_name' => 'field_gotowebinar_webinar_date',
    'label' => 'GoToWebinar webinar date',
    'required' => 1,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'display_all_day' => 0,
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'node-webinar_registration-field_gotowebinar_webinar_id'
  $field_instances['node-webinar_registration-field_gotowebinar_webinar_id'] = array(
    'bundle' => 'webinar_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
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
    'field_name' => 'field_gotowebinar_webinar_id',
    'label' => 'GoToWebinar webinar ID',
    'required' => 1,
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
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'node-webinar_registration-field_gotowebinar_webinar_name'
  $field_instances['node-webinar_registration-field_gotowebinar_webinar_name'] = array(
    'bundle' => 'webinar_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_gotowebinar_webinar_name',
    'label' => 'GoToWebinar webinar name',
    'required' => 1,
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

  // Exported field_instance: 'node-webinar_registration-field_image'
  $field_instances['node-webinar_registration-field_image'] = array(
    'bundle' => 'webinar_registration',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
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
    'field_name' => 'field_image',
    'label' => 'Image',
    'required' => 0,
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
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'node-webinar_registration-field_master_accelaworks_id'
  $field_instances['node-webinar_registration-field_master_accelaworks_id'] = array(
    'bundle' => 'webinar_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
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
    'field_name' => 'field_master_accelaworks_id',
    'label' => 'Master AccelaWorks ID',
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
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'node-webinar_registration-field_master_leadworks_id'
  $field_instances['node-webinar_registration-field_master_leadworks_id'] = array(
    'bundle' => 'webinar_registration',
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
        'module' => 'number',
        'settings' => array(
          'decimal_separator' => '.',
          'prefix_suffix' => TRUE,
          'scale' => 0,
          'thousand_separator' => ' ',
        ),
        'type' => 'number_integer',
        'weight' => 15,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_master_leadworks_id',
    'label' => 'Master Leadworks ID',
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
      'settings' => array(),
      'type' => 'number',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'node-webinar_registration-field_post_launch_banner'
  $field_instances['node-webinar_registration-field_post_launch_banner'] = array(
    'bundle' => 'webinar_registration',
    'deleted' => 0,
    'description' => 'Not used when the webinar is part of a webinar series.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_post_launch_banner',
    'label' => 'Post-launch banner',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'alt_field_required' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1042x300',
      'min_resolution' => '',
      'title_field' => 0,
      'title_field_required' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'node-webinar_registration-field_pre_launch_banner'
  $field_instances['node-webinar_registration-field_pre_launch_banner'] = array(
    'bundle' => 'webinar_registration',
    'deleted' => 0,
    'description' => 'Required for standalone webinars. Not used when the webinar is part of a webinar series.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 9,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_pre_launch_banner',
    'label' => 'Pre-launch banner',
    'required' => 0,
    'settings' => array(
      'alt_field' => 0,
      'alt_field_required' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '1042x300',
      'min_resolution' => '',
      'title_field' => 0,
      'title_field_required' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 2,
    ),
  );

  // Exported field_instance: 'node-webinar_registration-field_sponsor_logo'
  $field_instances['node-webinar_registration-field_sponsor_logo'] = array(
    'bundle' => 'webinar_registration',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 4,
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
    'field_name' => 'field_sponsor_logo',
    'label' => 'Sponsor Logo',
    'required' => 0,
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
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'node-webinar_registration-field_tags'
  $field_instances['node-webinar_registration-field_tags'] = array(
    'bundle' => 'webinar_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 18,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'module' => 'taxonomy',
        'settings' => array(),
        'type' => 'taxonomy_term_reference_link',
        'weight' => 18,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_tags',
    'label' => 'Tags',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'autocomplete_path' => 'taxonomy/autocomplete',
        'size' => 60,
      ),
      'type' => 'taxonomy_autocomplete',
      'weight' => 15,
    ),
  );

  // Exported field_instance: 'node-webinar_registration-field_viddler_id'
  $field_instances['node-webinar_registration-field_viddler_id'] = array(
    'bundle' => 'webinar_registration',
    'deleted' => 0,
    'description' => 'Enter the Viddler ID of the recorded webinar for display on demand.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'viddler',
        'settings' => array(),
        'type' => 'viddler_default',
        'weight' => 11,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'module' => 'viddler',
        'settings' => array(),
        'type' => 'viddler_default',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_viddler_id',
    'label' => 'On demand Viddler Id',
    'required' => 0,
    'settings' => array(
      'dimension' => array(
        'full' => array(
          'height' => 365,
          'width' => 430,
        ),
      ),
      'file_directory' => 'videos/viddler',
      'file_extensions' => 'mp4 ogg avi mov wmv flv ogv webm m4v',
      'input_type' => array(),
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'viddler',
      'settings' => array(
        'dimension' => array(
          'full' => array(
            'height' => 365,
            'width' => 430,
          ),
        ),
      ),
      'type' => 'viddler_widget',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'node-webinar_registration-field_waywire_video'
  $field_instances['node-webinar_registration-field_waywire_video'] = array(
    'bundle' => 'webinar_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'waywire',
        'settings' => array(
          'waywire_bottom' => 0,
          'waywire_companion' => 0,
          'waywire_embed_hidden' => 0,
          'waywire_height' => '',
          'waywire_hp' => 0,
          'waywire_init_autoplay' => NULL,
          'waywire_layout' => '',
          'waywire_link_target' => '',
          'waywire_manual_controls' => 0,
          'waywire_mute' => 0,
          'waywire_no_tabs' => 0,
          'waywire_player' => 'cvp',
          'waywire_read_more' => 0,
          'waywire_show_description' => 0,
          'waywire_size' => 'responsive',
          'waywire_sync_ad' => 0,
          'waywire_template' => '',
          'waywire_title_height' => '',
          'waywire_width' => '',
        ),
        'type' => 'waywire_video_iframe',
        'weight' => 19,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'hidden',
        'module' => 'waywire',
        'settings' => array(
          'waywire_bottom' => 0,
          'waywire_companion' => 0,
          'waywire_embed_hidden' => 0,
          'waywire_height' => '',
          'waywire_hp' => 0,
          'waywire_init_autoplay' => NULL,
          'waywire_layout' => '',
          'waywire_link_target' => '',
          'waywire_manual_controls' => 0,
          'waywire_mute' => 0,
          'waywire_no_tabs' => 0,
          'waywire_player' => 'cvp',
          'waywire_read_more' => 0,
          'waywire_show_description' => 0,
          'waywire_size' => 'responsive',
          'waywire_sync_ad' => 0,
          'waywire_template' => '',
          'waywire_title_height' => '',
          'waywire_width' => '',
        ),
        'type' => 'waywire_video_iframe',
        'weight' => 19,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_waywire_video',
    'label' => 'On Demand Waywire Video',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'waywire',
      'settings' => array(
        'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
      ),
      'type' => 'waywire',
      'weight' => 18,
    ),
  );

  // Exported field_instance: 'node-webinar_registration-field_webtracking_name'
  $field_instances['node-webinar_registration-field_webtracking_name'] = array(
    'bundle' => 'webinar_registration',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter a value to report page visits to Silverpop',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
      'webinar_series_part' => array(
        'label' => 'above',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 13,
      ),
    ),
    'entity_type' => 'node',
    'field_name' => 'field_webtracking_name',
    'label' => 'Webtracking name',
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
      'weight' => 7,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('AccelaWorks Billcode');
  t('Body');
  t('Company');
  t('Content PDF');
  t('Disclaimer');
  t('Enter a value to report page visits to Silverpop');
  t('Enter the Viddler ID of the recorded webinar for display on demand.');
  t('Form header');
  t('GoToWebinar webinar ID');
  t('GoToWebinar webinar date');
  t('GoToWebinar webinar name');
  t('Image');
  t('Master AccelaWorks ID');
  t('Master Leadworks ID');
  t('Not used when the webinar is part of a webinar series.');
  t('On Demand Waywire Video');
  t('On demand Viddler Id');
  t('Post-launch banner');
  t('Pre-launch banner');
  t('Required for standalone webinars. Not used when the webinar is part of a webinar series.');
  t('Speaker');
  t('Sponsor Logo');
  t('Tags');
  t('Terms');
  t('Upload the content to be delivered after registration');
  t('Webtracking name');

  return $field_instances;
}
