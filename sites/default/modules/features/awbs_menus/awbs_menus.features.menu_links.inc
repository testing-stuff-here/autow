<?php
/**
 * @file
 * awbs_menus.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function awbs_menus_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-mobile-main-menu_aaron-hand:aaron-hand
  $menu_links['menu-mobile-main-menu_aaron-hand:aaron-hand'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'aaron-hand',
    'router_path' => 'aaron-hand',
    'link_title' => 'Aaron Hand',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'AW Editors/Aaron Hand\');',
      ),
      'identifier' => 'menu-mobile-main-menu_aaron-hand:aaron-hand',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_aw-editors:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_about:node/9549
  $menu_links['menu-mobile-main-menu_about:node/9549'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'node/9549',
    'router_path' => 'node/%',
    'link_title' => 'About',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'parent',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'ABOUT\');',
      ),
      'identifier' => 'menu-mobile-main-menu_about:node/9549',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-main-menu_advertise:https://www.pmmimediagroup.com/aw/automation-world
  $menu_links['menu-mobile-main-menu_advertise:https://www.pmmimediagroup.com/aw/automation-world'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'https://www.pmmimediagroup.com/aw/automation-world',
    'router_path' => '',
    'link_title' => 'Advertise',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'parent',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'ADVERTISE\');',
      ),
      'identifier' => 'menu-mobile-main-menu_advertise:https://www.pmmimediagroup.com/aw/automation-world',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-main-menu_aerospace:factory-automation/aerospace
  $menu_links['menu-mobile-main-menu_aerospace:factory-automation/aerospace'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'factory-automation/aerospace',
    'router_path' => 'factory-automation/aerospace',
    'link_title' => 'Aerospace',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Factory/Aerospace\');',
      ),
      'identifier' => 'menu-mobile-main-menu_aerospace:factory-automation/aerospace',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_factory:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_asset-management:operations/asset-management
  $menu_links['menu-mobile-main-menu_asset-management:operations/asset-management'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'operations/asset-management',
    'router_path' => 'operations/asset-management',
    'link_title' => 'Asset Management',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Operations/Asset Management\');',
      ),
      'identifier' => 'menu-mobile-main-menu_asset-management:operations/asset-management',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_operations:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_automotive:factory-automation/automotive
  $menu_links['menu-mobile-main-menu_automotive:factory-automation/automotive'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'factory-automation/automotive',
    'router_path' => 'factory-automation/automotive',
    'link_title' => 'Automotive',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Factory/Automotive\');',
      ),
      'identifier' => 'menu-mobile-main-menu_automotive:factory-automation/automotive',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_factory:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_aw-editors:<nolink>
  $menu_links['menu-mobile-main-menu_aw-editors:<nolink>'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'AW Editors',
    'options' => array(
      'identifier' => 'menu-mobile-main-menu_aw-editors:<nolink>',
      'attributes' => array(
        'class' => array(
          0 => 'parent',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -49,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-main-menu_batch-manufacturing:engineering/batch-manufacturing
  $menu_links['menu-mobile-main-menu_batch-manufacturing:engineering/batch-manufacturing'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'engineering/batch-manufacturing',
    'router_path' => 'engineering/batch-manufacturing',
    'link_title' => 'Batch Manufacturing',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Engineering/Batch Manufacturing\');',
      ),
      'identifier' => 'menu-mobile-main-menu_batch-manufacturing:engineering/batch-manufacturing',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_engineering:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_chemical:process-automation/chemical
  $menu_links['menu-mobile-main-menu_chemical:process-automation/chemical'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'process-automation/chemical',
    'router_path' => 'process-automation/chemical',
    'link_title' => 'Chemical',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Process/Chemical\');',
      ),
      'identifier' => 'menu-mobile-main-menu_chemical:process-automation/chemical',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_process:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_communication:it/communication
  $menu_links['menu-mobile-main-menu_communication:it/communication'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'it/communication',
    'router_path' => 'it/communication',
    'link_title' => 'Communication',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'IT/Communication\');',
      ),
      'identifier' => 'menu-mobile-main-menu_communication:it/communication',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_it:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_continuous-process:engineering/continuous-process
  $menu_links['menu-mobile-main-menu_continuous-process:engineering/continuous-process'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'engineering/continuous-process',
    'router_path' => 'engineering/continuous-process',
    'link_title' => 'Continuous Process',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Engineering/Continuous Process\');',
      ),
      'identifier' => 'menu-mobile-main-menu_continuous-process:engineering/continuous-process',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_engineering:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_control:products/control
  $menu_links['menu-mobile-main-menu_control:products/control'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'products/control',
    'router_path' => 'products/control',
    'link_title' => 'Control',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Products/Control\');',
      ),
      'identifier' => 'menu-mobile-main-menu_control:products/control',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -49,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_products:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_databases:it/databases
  $menu_links['menu-mobile-main-menu_databases:it/databases'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'it/databases',
    'router_path' => 'it/databases',
    'link_title' => 'Databases',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'IT/Databases\');',
      ),
      'identifier' => 'menu-mobile-main-menu_databases:it/databases',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_it:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_david-greenfield:david-greenfield
  $menu_links['menu-mobile-main-menu_david-greenfield:david-greenfield'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'david-greenfield',
    'router_path' => 'david-greenfield',
    'link_title' => 'David Greenfield',
    'options' => array(
      'identifier' => 'menu-mobile-main-menu_david-greenfield:david-greenfield',
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'AW Editors/David Greenfield\');',
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_aw-editors:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_design:engineering/design
  $menu_links['menu-mobile-main-menu_design:engineering/design'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'engineering/design',
    'router_path' => 'engineering/design',
    'link_title' => 'Design',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Engineering/Design\');',
      ),
      'identifier' => 'menu-mobile-main-menu_design:engineering/design',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_engineering:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_discrete-manufacturing:engineering/discrete-manufacturing
  $menu_links['menu-mobile-main-menu_discrete-manufacturing:engineering/discrete-manufacturing'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'engineering/discrete-manufacturing',
    'router_path' => 'engineering/discrete-manufacturing',
    'link_title' => 'Discrete Manufacturing',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Engineering/Discrete Manufacturing\');',
      ),
      'identifier' => 'menu-mobile-main-menu_discrete-manufacturing:engineering/discrete-manufacturing',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_engineering:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_drives--motors:products/drives-motors
  $menu_links['menu-mobile-main-menu_drives--motors:products/drives-motors'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'products/drives-motors',
    'router_path' => 'products/drives-motors',
    'link_title' => 'Drives & Motors',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Products/Drives & Motors\');',
      ),
      'identifier' => 'menu-mobile-main-menu_drives--motors:products/drives-motors',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_products:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_energy-management:products/energy-management
  $menu_links['menu-mobile-main-menu_energy-management:products/energy-management'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'products/energy-management',
    'router_path' => 'products/energy-management',
    'link_title' => 'Energy Management',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Products/Energy Management\');',
      ),
      'identifier' => 'menu-mobile-main-menu_energy-management:products/energy-management',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_products:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_engineering:<nolink>
  $menu_links['menu-mobile-main-menu_engineering:<nolink>'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Engineering',
    'options' => array(
      'identifier' => 'menu-mobile-main-menu_engineering:<nolink>',
      'attributes' => array(
        'class' => array(
          0 => 'parent',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -45,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-main-menu_engineering:engineering
  $menu_links['menu-mobile-main-menu_engineering:engineering'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'engineering',
    'router_path' => 'engineering',
    'link_title' => 'Engineering',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Engineering\');',
      ),
      'identifier' => 'menu-mobile-main-menu_engineering:engineering',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_engineering:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_ethernet:it/ethernet
  $menu_links['menu-mobile-main-menu_ethernet:it/ethernet'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'it/ethernet',
    'router_path' => 'it/ethernet',
    'link_title' => 'Ethernet',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'IT/Ethernet\');',
      ),
      'identifier' => 'menu-mobile-main-menu_ethernet:it/ethernet',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_it:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_fabricated-metals:factory-automation/fabricated-metals
  $menu_links['menu-mobile-main-menu_fabricated-metals:factory-automation/fabricated-metals'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'factory-automation/fabricated-metals',
    'router_path' => 'factory-automation/fabricated-metals',
    'link_title' => 'Fabricated Metals',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Factory/Fabricated Metals\');',
      ),
      'identifier' => 'menu-mobile-main-menu_fabricated-metals:factory-automation/fabricated-metals',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_factory:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_factory:<nolink>
  $menu_links['menu-mobile-main-menu_factory:<nolink>'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Factory',
    'options' => array(
      'identifier' => 'menu-mobile-main-menu_factory:<nolink>',
      'attributes' => array(
        'class' => array(
          0 => 'parent',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -47,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-main-menu_factory:factory-automation
  $menu_links['menu-mobile-main-menu_factory:factory-automation'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'factory-automation',
    'router_path' => 'factory-automation',
    'link_title' => 'Factory',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Factory\');',
      ),
      'identifier' => 'menu-mobile-main-menu_factory:factory-automation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_factory:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_fieldbuses:it/communication
  $menu_links['menu-mobile-main-menu_fieldbuses:it/communication'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'it/communication',
    'router_path' => 'it/communication',
    'link_title' => 'Fieldbuses',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'IT/Fieldbuses\');',
      ),
      'identifier' => 'menu-mobile-main-menu_fieldbuses:it/communication',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_it:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_food--beverage:process-automation/food-beverage
  $menu_links['menu-mobile-main-menu_food--beverage:process-automation/food-beverage'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'process-automation/food-beverage',
    'router_path' => 'process-automation/food-beverage',
    'link_title' => 'Food & Beverage',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Process/Food & Beverage\');',
      ),
      'identifier' => 'menu-mobile-main-menu_food--beverage:process-automation/food-beverage',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_process:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_hmi-hardware:taxonomy/term/2699
  $menu_links['menu-mobile-main-menu_hmi-hardware:taxonomy/term/2699'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'taxonomy/term/2699',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'HMI Hardware',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Products/HMI Hardware\');',
      ),
      'identifier' => 'menu-mobile-main-menu_hmi-hardware:taxonomy/term/2699',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_products:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_instrumentation:products/instrumentation
  $menu_links['menu-mobile-main-menu_instrumentation:products/instrumentation'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'products/instrumentation',
    'router_path' => 'products/instrumentation',
    'link_title' => 'Instrumentation',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Products/Instrumentation\');',
      ),
      'identifier' => 'menu-mobile-main-menu_instrumentation:products/instrumentation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_products:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_it:<nolink>
  $menu_links['menu-mobile-main-menu_it:<nolink>'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'IT',
    'options' => array(
      'identifier' => 'menu-mobile-main-menu_it:<nolink>',
      'attributes' => array(
        'class' => array(
          0 => 'parent',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -44,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-main-menu_it:it
  $menu_links['menu-mobile-main-menu_it:it'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'it',
    'router_path' => 'it',
    'link_title' => 'IT',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'IT\');',
      ),
      'identifier' => 'menu-mobile-main-menu_it:it',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_it:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_lean-manufacturing:operations/lean-manufacturing
  $menu_links['menu-mobile-main-menu_lean-manufacturing:operations/lean-manufacturing'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'operations/lean-manufacturing',
    'router_path' => 'operations/lean-manufacturing',
    'link_title' => 'Lean Manufacturing',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Operations/Lean Manufacturing\');',
      ),
      'identifier' => 'menu-mobile-main-menu_lean-manufacturing:operations/lean-manufacturing',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_operations:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_life-sciences:process-automation/life-sciences
  $menu_links['menu-mobile-main-menu_life-sciences:process-automation/life-sciences'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'process-automation/life-sciences',
    'router_path' => 'process-automation/life-sciences',
    'link_title' => 'Life Sciences',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Process/Life Sciences\');',
      ),
      'identifier' => 'menu-mobile-main-menu_life-sciences:process-automation/life-sciences',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_process:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_magazine:node/9304
  $menu_links['menu-mobile-main-menu_magazine:node/9304'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'node/9304',
    'router_path' => 'node/%',
    'link_title' => 'Magazine',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'parent',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'MAGAZINE\');',
      ),
      'identifier' => 'menu-mobile-main-menu_magazine:node/9304',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-main-menu_mes:it/mes
  $menu_links['menu-mobile-main-menu_mes:it/mes'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'it/mes',
    'router_path' => 'it/mes',
    'link_title' => 'MES',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'IT/MES\');',
      ),
      'identifier' => 'menu-mobile-main-menu_mes:it/mes',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_it:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_networking:it/networking
  $menu_links['menu-mobile-main-menu_networking:it/networking'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'it/networking',
    'router_path' => 'it/networking',
    'link_title' => 'Networking',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'IT/Networking\');',
      ),
      'identifier' => 'menu-mobile-main-menu_networking:it/networking',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_it:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_networking:products/networking
  $menu_links['menu-mobile-main-menu_networking:products/networking'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'products/networking',
    'router_path' => 'products/networking',
    'link_title' => 'Networking',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Products/Networking\');',
      ),
      'identifier' => 'menu-mobile-main-menu_networking:products/networking',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_products:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_oem:factory-automation/oem
  $menu_links['menu-mobile-main-menu_oem:factory-automation/oem'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'factory-automation/oem',
    'router_path' => 'factory-automation/oem',
    'link_title' => 'OEM',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Factory/OEM\');',
      ),
      'identifier' => 'menu-mobile-main-menu_oem:factory-automation/oem',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_factory:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_oil--gas:process-automation/oil-gas
  $menu_links['menu-mobile-main-menu_oil--gas:process-automation/oil-gas'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'process-automation/oil-gas',
    'router_path' => 'process-automation/oil-gas',
    'link_title' => 'Oil & Gas',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Process/Oil & Gas\');',
      ),
      'identifier' => 'menu-mobile-main-menu_oil--gas:process-automation/oil-gas',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_process:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_operations:<nolink>
  $menu_links['menu-mobile-main-menu_operations:<nolink>'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Operations',
    'options' => array(
      'identifier' => 'menu-mobile-main-menu_operations:<nolink>',
      'attributes' => array(
        'class' => array(
          0 => 'parent',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -43,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-main-menu_operations:operations
  $menu_links['menu-mobile-main-menu_operations:operations'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'operations',
    'router_path' => 'operations',
    'link_title' => 'Operations',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Operations\');',
      ),
      'identifier' => 'menu-mobile-main-menu_operations:operations',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_operations:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_packaging:factory-automation/packaging
  $menu_links['menu-mobile-main-menu_packaging:factory-automation/packaging'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'factory-automation/packaging',
    'router_path' => 'factory-automation/packaging',
    'link_title' => 'Packaging',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Factory/Packaging\');',
      ),
      'identifier' => 'menu-mobile-main-menu_packaging:factory-automation/packaging',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_factory:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_pat-reynolds:pat-reynolds
  $menu_links['menu-mobile-main-menu_pat-reynolds:pat-reynolds'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'pat-reynolds',
    'router_path' => 'pat-reynolds',
    'link_title' => 'Pat Reynolds',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'AW Editors/Pat Reynolds\');',
      ),
      'identifier' => 'menu-mobile-main-menu_pat-reynolds:pat-reynolds',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_aw-editors:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_power-generation:process-automation/power-generation
  $menu_links['menu-mobile-main-menu_power-generation:process-automation/power-generation'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'process-automation/power-generation',
    'router_path' => 'process-automation/power-generation',
    'link_title' => 'Power Generation',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Process/Power Generation\');',
      ),
      'identifier' => 'menu-mobile-main-menu_power-generation:process-automation/power-generation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_process:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_process:<nolink>
  $menu_links['menu-mobile-main-menu_process:<nolink>'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Process',
    'options' => array(
      'identifier' => 'menu-mobile-main-menu_process:<nolink>',
      'attributes' => array(
        'class' => array(
          0 => 'parent',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -46,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-main-menu_process:process-automation
  $menu_links['menu-mobile-main-menu_process:process-automation'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'process-automation',
    'router_path' => 'process-automation',
    'link_title' => 'Process',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Process\');',
      ),
      'identifier' => 'menu-mobile-main-menu_process:process-automation',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_process:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_production-management:taxonomy/term/2747
  $menu_links['menu-mobile-main-menu_production-management:taxonomy/term/2747'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'taxonomy/term/2747',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Production Management',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Operations/Production Management\');',
      ),
      'identifier' => 'menu-mobile-main-menu_production-management:taxonomy/term/2747',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_operations:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_products:<nolink>
  $menu_links['menu-mobile-main-menu_products:<nolink>'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => '<nolink>',
    'router_path' => '<nolink>',
    'link_title' => 'Products',
    'options' => array(
      'identifier' => 'menu-mobile-main-menu_products:<nolink>',
      'attributes' => array(
        'class' => array(
          0 => 'parent',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 1,
    'expanded' => 1,
    'weight' => -48,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-main-menu_products:products
  $menu_links['menu-mobile-main-menu_products:products'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'products',
    'router_path' => 'products',
    'link_title' => 'Products',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Products\');',
      ),
      'identifier' => 'menu-mobile-main-menu_products:products',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_products:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_pulp--paper:process-automation/pulp-paper
  $menu_links['menu-mobile-main-menu_pulp--paper:process-automation/pulp-paper'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'process-automation/pulp-paper',
    'router_path' => 'process-automation/pulp-paper',
    'link_title' => 'Pulp & Paper',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Process/Pulp & Paper\');',
      ),
      'identifier' => 'menu-mobile-main-menu_pulp--paper:process-automation/pulp-paper',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_process:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_sensors:products/sensors
  $menu_links['menu-mobile-main-menu_sensors:products/sensors'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'products/sensors',
    'router_path' => 'products/sensors',
    'link_title' => 'Sensors',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Products/Sensors\');',
      ),
      'identifier' => 'menu-mobile-main-menu_sensors:products/sensors',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_products:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_stephanie-neil:stephanie-neil
  $menu_links['menu-mobile-main-menu_stephanie-neil:stephanie-neil'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'stephanie-neil',
    'router_path' => 'stephanie-neil',
    'link_title' => 'Stephanie Neil',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'AW Editors/Stephanie Neil\');',
      ),
      'identifier' => 'menu-mobile-main-menu_stephanie-neil:stephanie-neil',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -48,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_aw-editors:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_subscribe:node/13046
  $menu_links['menu-mobile-main-menu_subscribe:node/13046'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'node/13046',
    'router_path' => 'node/%',
    'link_title' => 'Subscribe',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'parent',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'SUBSCRIBE\');',
      ),
      'identifier' => 'menu-mobile-main-menu_subscribe:node/13046',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -50,
    'customized' => 1,
  );
  // Exported menu link: menu-mobile-main-menu_supply-chain:operations/supply-chain
  $menu_links['menu-mobile-main-menu_supply-chain:operations/supply-chain'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'operations/supply-chain',
    'router_path' => 'operations/supply-chain',
    'link_title' => 'Supply Chain',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'AW Editors/Supply Chain\');',
      ),
      'identifier' => 'menu-mobile-main-menu_supply-chain:operations/supply-chain',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_operations:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_system-integration:engineering/system-integration
  $menu_links['menu-mobile-main-menu_system-integration:engineering/system-integration'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'engineering/system-integration',
    'router_path' => 'engineering/system-integration',
    'link_title' => 'System Integration',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Engineering/System Integration\');',
      ),
      'identifier' => 'menu-mobile-main-menu_system-integration:engineering/system-integration',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_engineering:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_training:operations/workforce
  $menu_links['menu-mobile-main-menu_training:operations/workforce'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'operations/workforce',
    'router_path' => 'operations/workforce',
    'link_title' => 'Training',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Operations/Training\');',
      ),
      'identifier' => 'menu-mobile-main-menu_training:operations/workforce',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_operations:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_valves:taxonomy/term/2685
  $menu_links['menu-mobile-main-menu_valves:taxonomy/term/2685'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'taxonomy/term/2685',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Valves',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Engineering/Valves\');',
      ),
      'identifier' => 'menu-mobile-main-menu_valves:taxonomy/term/2685',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_engineering:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_waterwastewater:process-automation/water-wastewater
  $menu_links['menu-mobile-main-menu_waterwastewater:process-automation/water-wastewater'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'process-automation/water-wastewater',
    'router_path' => 'process-automation/water-wastewater',
    'link_title' => 'Water/Wastewater',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Process/Water-Wastewater\');',
      ),
      'identifier' => 'menu-mobile-main-menu_waterwastewater:process-automation/water-wastewater',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_process:<nolink>',
  );
  // Exported menu link: menu-mobile-main-menu_workforce:operations/workforce
  $menu_links['menu-mobile-main-menu_workforce:operations/workforce'] = array(
    'menu_name' => 'menu-mobile-main-menu',
    'link_path' => 'operations/workforce',
    'router_path' => 'operations/workforce',
    'link_title' => 'Workforce',
    'options' => array(
      'attributes' => array(
        'class' => array(
          0 => 'child',
        ),
        'onclick' => 'ga(\'send\', \'event\', \'Mobile Hamburger Menu\', \'Drop Down\', \'Operations/Workforce\');',
      ),
      'identifier' => 'menu-mobile-main-menu_workforce:operations/workforce',
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 0,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'customized' => 1,
    'parent_identifier' => 'menu-mobile-main-menu_operations:<nolink>',
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('AW Editors');
  t('Aaron Hand');
  t('About');
  t('Advertise');
  t('Aerospace');
  t('Asset Management');
  t('Automotive');
  t('Batch Manufacturing');
  t('Chemical');
  t('Communication');
  t('Continuous Process');
  t('Control');
  t('Databases');
  t('David Greenfield');
  t('Design');
  t('Discrete Manufacturing');
  t('Drives & Motors');
  t('Energy Management');
  t('Engineering');
  t('Ethernet');
  t('Fabricated Metals');
  t('Factory');
  t('Fieldbuses');
  t('Food & Beverage');
  t('HMI Hardware');
  t('IT');
  t('Instrumentation');
  t('Lean Manufacturing');
  t('Life Sciences');
  t('MES');
  t('Magazine');
  t('Networking');
  t('OEM');
  t('Oil & Gas');
  t('Operations');
  t('Packaging');
  t('Pat Reynolds');
  t('Power Generation');
  t('Process');
  t('Production Management');
  t('Products');
  t('Pulp & Paper');
  t('Sensors');
  t('Stephanie Neil');
  t('Subscribe');
  t('Supply Chain');
  t('System Integration');
  t('Training');
  t('Valves');
  t('Water/Wastewater');
  t('Workforce');

  return $menu_links;
}
