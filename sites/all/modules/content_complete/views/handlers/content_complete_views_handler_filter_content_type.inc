<?php

/**
 *  @file
 *  This defines a views handler to filter nodes by whether or not they're Content-Complete-enabled.
 */

class content_complete_views_handler_filter_content_type extends views_handler_filter_boolean_operator {
  function query() {
    $types = array_keys(content_complete_get_enabled_types());
    $this->query->add_where(0, 'node.type', $types, empty($this->value) ? 'NOT IN' : 'IN'); 
  }
}