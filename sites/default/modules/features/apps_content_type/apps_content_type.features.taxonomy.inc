<?php
/**
 * @file
 * apps_content_type.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function apps_content_type_taxonomy_default_vocabularies() {
  return array(
    'app_platforms_os' => array(
      'name' => 'App Platforms/OS',
      'machine_name' => 'app_platforms_os',
      'description' => 'List of platforms/operating systems',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
