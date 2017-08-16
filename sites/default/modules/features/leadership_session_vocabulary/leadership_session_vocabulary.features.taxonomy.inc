<?php
/**
 * @file
 * leadership_session_vocabulary.features.taxonomy.inc
 */

/**
 * Implementation of hook_taxonomy_default_vocabularies().
 */
function leadership_session_vocabulary_taxonomy_default_vocabularies() {
  return array(
    'leadership_session' => array(
      'name' => 'Leadership Session',
      'machine_name' => 'leadership_session',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
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
