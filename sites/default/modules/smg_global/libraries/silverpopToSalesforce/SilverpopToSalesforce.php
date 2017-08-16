<?php

/**
 * @file
 * Holds Silverpop to Salesforce Functionality
 */
class SilverpopToSalesforce {

  public $ringLeadUrl = 'https://salesforce.ringlead.com/cgi-bin/2557/1/dedup.pl';

  /**
   * Mapping array: Silverpop Field => Salesforce Field.
   */
  public $fieldNameMapping = array(
    'Email' => 'Email',
    'AW 3rd party email' => 'AW_3rd_Party_Direct_Mail__c',
    'AW Automation Type' => 'AW_Automation_Type__c',
    'AW Company Size' => 'AW_Classification__c',
    'AW Demo Date' => 'AW_Demographic_Date__c',
    'AW Industry' => 'AW_Industry__c',
    'AW Industry Other' => 'AW_Industry_Other__c',
    'AW Job Duties' => 'AW_Job_Duties__c',
    'AW Job Duties Other' => 'AW_Job_Duties_Other__c',
    'AW Mag Pedigree' => 'AW_Mag_Pedigree__c',
    'AW Mag Request' => 'PW_Mag_Request__c',
    'AW Mag Requested Version' => 'PW_Mag_Requested_Version__c',
    'AW Management' => 'AW_Management__c',
    'AW Management Level' => 'AW_Management_Level__c',
    'AW Omeda Reader Number' => 'AW_Omeda_Reader_Number__c',
    'AW Personal Identifier' => 'AW_Personal_Identifier__c',
    'AW Ver Date' => 'AW_Verification_Date__c',
    'City' => 'City',
    'Company' => 'Company',
    'Country' => 'Country',
    'CRM Lead Source' => 'LeadSource',
    'Fax' => 'Fax',
    'First name' => 'FirstName',
    'HCP 3rd party email' => 'HCP_3rd_Party_Direct_Mail__c',
    'HCP Classification' => 'HCP_Classification__c',
    'HCP Demo Date' => 'HCP_Demographic_Date__c',
    'HCP Mag Pedigree' => 'HCP_Mag_Pedigree__c',
    'HCP Mag Request' => 'HCP_Mag_Request__c',
    'HCP Mag Requested Version' => 'HCP_Mag_Requested_Version__c',
    'HCP Omeda Reader Number' => 'HCP_Omeda_Reader_Number__c',
    'HCP Personal Identifier' => 'HCP_Personal_Identifier__c',
    'HCP Ver Date' => 'HCP_Verification_Date__c',
    'Last name' => 'LastName',
    'Phone' => 'Phone',
    'PP OEM Annual Revenues' => 'PP_OEM_Annual_Revenues__c',
    'PP OEM Industry' => 'PP_OEM_Industry__c',
    'PP OEM Industry Other' => 'PP_OEM_Industry_Other__c',
    'PP OEM Job Duties' => 'PP_OEM_Job_Duties__c',
    'PP OEM Job Duties Other' => 'PP_OEM_Job_Duties_Other__c',
    'PP OEM Verification Date' => 'PP_OEM_Verification_Date__c',
    'PW 3rd party email' => 'PW_3rd_Party_Direct_Mail__c',
    'PW Classification' => 'PW_Classification__c',
    'PW Demo Date' => 'PW_Demographic_Date__c',
    'PW HCP Buying influence' => 'PW_HCP_Buying_Influence__c',
    'PW HCP Company Size' => 'PW_HCP_Company_Size__c',
    'PW HCP Contract Packaging' => 'PW_HCP_Contract_Packaging__c',
    'PW HCP Industry' => 'PW_HCP_Industry__c',
    'PW HCP Industry Other' => 'PW_HCP_Industry_Other__c',
    'PW HCP Job Duties Multi Select' => 'PW_HCP_Job_Duties__c',
    'PW HCP Job Duties Other' => 'PW_HCP_Job_Duties_Other__c',
    'PW HCP Job Duties Primary' => 'PW_HCP_Job_Duty_Primary__c',
    'PW HCP Management' => 'PW_HCP_Management__c',
    'PW HCP Management Level' => 'PW_HCP_Management_Level__c',
    'PW HCP Perform Contract Packaging' => 'PW_HCP_Perform_Contract_Packaging__c',
    'PW HCP Private Label' => 'PW_HCP_Private_Label__c',
    'PW Mag Pedigree' => 'PW_Mag_Pedigree__c',
    'PW Mag Request' => 'PW_Mag_Request__c',
    'PW Mag Requested Version' => 'PW_Mag_Requested_Version__c',
    'PW Omeda Reader Number' => 'PW_Omeda_Reader_Number__c',
    'PW Personal Identifier' => 'PW_Personal_Identifier__c',
    'PW Ver Date' => 'PW_Verification_Date__c',
    'Audit Touch Points' => 'Audit_Touch_Points__c',
    'Title' => 'Title',
    'Zip' => 'PostalCode'
  );

  /**
   * PW HCP Industry Silvepop => Salesforce Field mapping.
   */
  public $pwIndustry = array(
    'Apparel, Textiles'                                                       => 'Apparel, Textiles',
    'Baked Goods, Cookies, Crackers, Pasta, Snack Foods'                      => 'Baked Goods,Cookies,Crackers,Pasta,Snack',
    'Beverages (Soft Drinks, Juices, Alcoholic Beverages, Coffee, Tea)'       => 'Beverages',
    'Biological/Biopharmaceutical'                                            => 'Biological / Biopharmaceutical',
    'Cereals, Breakfast Foods'                                                => 'Cereals, Breakfast Foods',
    'Chemicals, Paints, Adhesives'                                            => 'Chemicals, Paints, Adhesives',
    'Confectionery Products, Sugar'                                           => 'Confectionery Products, Sugar',
    'Consumer Electronics, Computers, Peripherals, Household Appliances'      => 'ConsElec,Comps,Peripherals,HouseholdApps',
    'Controls, Components, Integration Services, Line Automation'             => 'Controls,Components,IntServices,LineAuto',
    'Converted Package or Component (Film, Closures, Pouches, Lidding, etc.)' => 'Converted Package or Component',
    'Consultant/Integrator'                                                   => 'Consultant/Integrator',
    'Cosmetics, Toiletries, Baby Products'                                    => 'Cosmetics, Toiletries, Baby Products',
    'Dairy Products'                                                          => 'Dairy Products',
    'Fats, Oils'                                                              => 'Fats, Oils',
    'Food Stores, Food Service'                                               => 'Food Stores, Food Service',
    'Fruits, Vegetables (Fresh, Canned, Frozen)'                              => 'Fruits,Vegetables(Fresh, Canned, Frozen)',
    'Government'                                                              => 'Government',
    'Grains, Seeds, Beans, Flour, Nuts'                                       => 'Grains, Seeds, Beans, Flour, Nuts',
    'Machinery, Electronic Equipment'                                         => 'Machinery, Electronic',
    'Meat, Poultry, Seafood'                                                  => 'Meat, Poultry, Seafood',
    'Medical Devices/Diagnostic Instruments'                                  => 'Medical Devices / Diagnostic Instruments',
    'Medical/Dental Instruments or Supplies'                                  => 'Medical/Dental Instruments or Supplies',
    'Metal, Glass, Wood Products'                                             => 'Metal, Glass, Wood Products',
    'Nutraceutical, Vitamin, Dietary Supplement'                              => 'Nutraceutical,Vitamin,Dietary Supplement',
    'Other'                                                                   => 'Other',
    'Other Food and Beverage Products'                                        => 'Other Food and Beverage Products',
    'Package Design Firm'                                                     => 'Package Design Firm',
    'Packaging Distributor'                                                   => 'Packaging Distributor',
    'Packaging Machinery'                                                     => 'Packaging Machinery',
    'Paper, Printed Products, Office Supplies'                                => 'Paper, Printed Products, Office Supplies',
    'Pet Foods, Animal Foods'                                                 => 'Pet Foods, Animal Foods',
    'Pharmaceutical'                                                          => 'Pharmaceutical',
    'Plastic, Rubber Products'                                                => 'Plastic, Rubber Products',
    'Raw Materials (Board, Resin, Additives, etc.)'                           => 'Raw Materials',
    'Soap, Household Cleaners, Other Household Products'                      => 'Soap,HouseholdCleaners,OtherHouseProds',
    'Soups, Sauces, Condiments, Dressings, Spices, Syrup, Powders'            => 'Soups,Sauces,Conds,Dressing,Spice,Syrup',
    'Toys, Games, Sporting Goods'                                             => 'Toys, Games, Sporting Goods',
    'Wholesalers, Distributors, Warehouses'                                   => 'Wholesalers, Distributors, Warehouses',
  );

  /**
   * PW HCP Contract Packaging Silverpop to Salesforce mapping.
   */
  public $pwContractPackagingMapping = array(
    'We currently use or plan to use contract packaging services' => 'Use contract packaging services',
    'We contract package for others'                              => 'Contract package for others',
    'None of the above'                                           => 'None',
    'Use contract packaging services'                             => 'Use contract packaging services',
    'Contract package for others'                                 => 'Contract package for others',
    'None'                                                        => 'None',
  );

  // PW HCP Job Duties Silverpop to Salesforce mapping.
  public $pwJobDutiesMapping = array(
    'Production/Operations/Quality'                               => 'Production/Operations/Quality',
    'Packaging Machinery Engineering'                             => 'Packaging Machinery Engineering',
    'Package Development Engineering/R&D'                         => 'Package Development Engineering/RD',
    'Package Design/Brand Management/Marketing'                   => 'Package Design/Brand Manage/Marketing',
    'Supply Chain: Logistics, Distribution, Warehouse Automation' => 'Supply Chain: Logistics, Distribution',
    'Regulatory Affairs, Validation/Compliance'                   => 'Regulatory Affairs, Validation/Comp',
    'Procurement'                                                 => 'Procurement',
    'Other'                                                       => 'Other',
  );

  // AW Industry Silverpop to Salesforce mapping.
  public $awIndustryMapping = array(
    'Aerospace, aircraft and defense products'                        => 'Aerospace, aircraft and defense products',
    'All Other Machinery (including material handling and conveying)' => 'All other machinery',
    'Alternative Energy (Wind, hydro, solar, and bio fuels)'          => 'Alternative Energy',
    'Auto, truck, rail, marine transportation'                        => 'Auto,truck,rail,marine transportation',
    'Automation Supplier'                                             => 'Automation Supplier',
    'Chemical Processing'                                             => 'Chemical Processing',
    'Communication devices and equipment'                             => 'Communication devices and equipment',
    'Computers, electronics, semiconductors'                          => 'Computers,electronics, semiconductors',
    'Construction, agricultural, mining equipment'                    => 'Construction, agricultural, mining equip',
    'Consulting or systems integration'                               => 'Consulting or systems integration',
    'Consumer Packaged Goods (Everything other than Food/Beverage)'   => 'Consumer Packaged Goods',
    'Electrical Utilities/Power Generation'                           => 'Electrical Utilities/Power Generation',
    'Fabricated Metals'                                               => 'Fabricated Metals',
    'Food and Beverage'                                               => 'Food and Beverage',
    'Instrumentation, control, measurement products'                  => 'Instrumentation,control,measurement prod',
    'Medical equipment and devices'                                   => 'Medical equipment and devices',
    'Oil and gas including LNG'                                       => 'Oil and gas including LNG',
    'Other'                                                           => 'Other',
    'Packaging, Printing, Converting Machinery'                       => 'Packaging,Printing,Converting Machinery',
    'Paper, Wood and Allied products'                                 => 'Paper, Wood and Allied products',
    'Pharmaceuticals'                                                 => 'Pharmaceuticals',
    'Plastics and rubber products'                                    => 'Plastics and rubber products',
    'Water and wastewater'                                            => 'Water and wastewater',
  );

  // AW Automation Type Silverpop to Salesforce mapping.
  public $automationTypeMapping = array(
    'Discrete manufacturing/factory automation' => 'Discrete manufacturing/factory auto.',
    'Batch/Hybrid processing'                   => 'Batch/Hybrid processing',
    'Continuous processing'                     => 'Continuous processing',
  );

  // Country Silverpop to Salesorce mapping.
  public $country_map = array(
    'AFGHANISTAN' => 'Afghanistan',
    'ALAND ISLANDS' => 'Aland Islands',
    'ALBANIA' => 'Albania',
    'ALGERIA' => 'Algeria',
    'AMERICAN SAMOA' => 'American Samoa',
    'ANDORRA' => 'Andorra',
    'ANGOLA' => 'Angola',
    'ANGUILLA' => 'Anguilla',
    'ANTARCTICA' => 'Antarctica',
    'ANTIGUA AND BARBUDA' => 'Antigua and Barbuda',
    'ANTIGUA' => 'Antigua and Barbuda',
    'ARGENTINA' => 'Argentina',
    'ARMENIA' => 'Armenia',
    'ARUBA' => 'Aruba',
    'AUSTRALIA' => 'Australia',
    'AUSTRIA' => 'Austria',
    'AZERBAIJAN' => 'Azerbaijan',
    'BAHAMAS' => 'Bahamas',
    'BAHRAIN' => 'Bahrain',
    'BANGLADESH' => 'Bangladesh',
    'BARBADOS' => 'Barbados',
    'BELARUS' => 'Belarus',
    'BELGIUM' => 'Belgium',
    'BELIZE' => 'Belize',
    'BENIN' => 'Benin',
    'BERMUDA' => 'Bermuda',
    'BHUTAN' => 'Bhutan',
    'BOLIVIA' => 'Bolivia',
    'BOSNIA AND HERZEGOVINA' => 'Bosnia and Herzegovina',
    'BOSNIA' => 'Bosnia and Herzegovina',
    'BOSNIA AND HERZEGO' => 'Bosnia and Herzegovina',
    'BOTSWANA' => 'Botswana',
    'BOUVET ISLAND' => 'Bouvet Island',
    'BRAZIL' => 'Brazil',
    'BRASIL' => 'Brazil',
    'BRITISH INDIAN OCEAN TERRITORY' => 'British Indian Ocean Territory',
    'BRITISH VIRGIN ISLANDS' => 'Virgin Islands, British',
    'BRUNEI' => 'Brunei Darussalam',
    'BULGARIA' => 'Bulgaria',
    'BURKINA FASO' => 'Burkina Faso',
    'BURUNDI' => 'Burundi',
    'CAMBODIA' => 'Cambodia',
    'CAMEROON' => 'Cameroon',
    'CANADA' => 'Canada',
    'CAPE VERDE' => 'Cape Verde',
    'CAYMAN ISLANDS' => 'Cayman Islands',
    'CENTRAL AFRICAN REPUBLIC' => 'Central African Republic',
    'CHAD' => 'Chad',
    'CHILE' => 'Chile',
    'CHINA' => 'China',
    'CHRISTMAS ISLAND' => 'Christmas Island',
    'COCOS (KEELING) ISLANDS' => 'Cocos (Keeling) Islands',
    'COLOMBIA' => 'Colombia',
    'COMOROS' => 'Comoros',
    'CONGO (BRAZZAVILLE)' => 'Congo',
    'CONGO' => 'Congo',
    'CONGO (KINSHASA)' => 'Congo, the Democratic Republic of the',
    'COOK ISLANDS' => 'Cook Islands',
    'COSTA RICA' => 'Costa Rica',
    'IVORY COAST' => 'Cote d\'Ivoire',
    'CROATIA' => 'Croatia',
    'CUBA' => 'Cuba',
    'CURAÇAO' => 'Curaçao',
    'CYPRUS' => 'Cyprus',
    'CZECH REPUBLIC' => 'Czech Republic',
    'DENMARK' => 'Denmark',
    'DJIBOUTI' => 'Djibouti',
    'DOMINICA' => 'Dominica',
    'DOMINICAN REPUBLIC' => 'Dominican Republic',
    'ECUADOR' => 'Ecuador',
    'EGYPT' => 'Egypt',
    'EL SALVADOR' => 'El Salvador',
    'EQUATORIAL GUINEA' => 'Equatorial Guinea',
    'ERITREA' => 'Eritrea',
    'ESTONIA' => 'Estonia',
    'ETHIOPIA' => 'Ethiopia',
    'FALKLAND ISLANDS' => 'Falkland Islands (Malvinas)',
    'FAROE ISLANDS' => 'Faroe Islands',
    'FIJI' => 'Fiji',
    'FINLAND' => 'Finland',
    'FRANCE' => 'France',
    'FRENCH GUIANA' => 'French Guiana',
    'FRENCH POLYNESIA' => 'French Polynesia',
    'FRENCH SOUTHERN TERRITORIES' => 'French Southern Territories',
    'GABON' => 'Gabon',
    'GAMBIA' => 'Gambia',
    'GEORGIA' => 'Georgia',
    'GERMANY' => 'Germany',
    'GHANA' => 'Ghana',
    'GIBRALTAR' => 'Gibraltar',
    'GREECE' => 'Greece',
    'GREENLAND' => 'Greenland',
    'GRENADA' => 'Grenada',
    'GUADELOUPE' => 'Guadeloupe',
    'GUAM' => '',
    'GUATEMALA' => 'Guatemala',
    'GUERNSEY' => 'Guernsey',
    'GUINEA' => 'Guinea',
    'GUINEA-BISSAU' => 'Guinea-Bissau',
    'GUYANA' => 'Guyana',
    'HAITI' => 'Haiti',
    'HEARD ISLAND AND MCDONALD ISLANDS' => 'Heard Island and McDonald Islands',
    'VATICAN' => 'Holy See (Vatican City State)',
    'HONDURAS' => 'Honduras',
    'HONG KONG S.A.R., CHINA' => 'Hong Kong S.A.R., China',
    'HONG KONG' => 'China',
    'HUNGARY' => 'Hungary',
    'ICELAND' => 'Iceland',
    'INDIA' => 'India',
    'INDONESIA' => 'Indonesia',
    'IRAN' => 'Iran',
    'IRAN ISLAMIC REPU' => 'Iran, Islamic Republic of',
    'IRAN (ISLAMIC REPU' => 'Iran, Islamic Republic of',
    'IRAN, ISLAMIC REPUBLIC OF' => 'Iran, Islamic Republic of',
    'IRAQ' => 'Iraq',
    'IRELAND' => 'Ireland',
    'NORTHERN IRELAND' => 'Ireland',
    'ISLE OF MAN' => 'Isle of Man',
    'ISRAEL' => 'Israel',
    'ITALY' => 'Italy',
    'JAMAICA' => 'Jamaica',
    'JAPAN' => 'Japan',
    'JERSEY' => 'Jersey',
    'JORDAN' => 'Jordan',
    'KAZAKHSTAN' => 'Kazakhstan',
    'KENYA' => 'Kenya',
    'KIRIBATI' => 'Kiribati',
    'NORTH KOREA' => 'Korea, Democratic People\'s Republic of',
    'SOUTH KOREA' => 'South Korea',
    'KOREA, REPUBLIC OF' => 'Korea, Republic of',
    'KOREA REPUBLIC OF' => 'Korea, Republic of',
    'KOREA' => 'Korea, Republic of',
    'KOSOVO' => '',
    'KUWAIT' => 'Kuwait',
    'KYRGYZSTAN' => 'Kyrgyzstan',
    'LAOS' => 'Lao People\'s Democratic Republic',
    'LATVIA' => 'Latvia',
    'LEBANON' => 'Lebanon',
    'LESOTHO' => 'Lesotho',
    'LIBERIA' => 'Liberia',
    'LIBYA' => 'Libya',
    'LIBYAN ARAB JAMAHIRIYA' => 'Libyan Arab Jamahiriya',
    'LIECHTENSTEIN' => 'Liechtenstein',
    'LITHUANIA' => 'Lithuania',
    'LUXEMBOURG' => 'Luxembourg',
    'MACAO S.A.R., CHINA' => 'Macao',
    'MACAO' => 'Macao',
    'MACAU' => 'Macao',
    'MACEDONIA' => 'Macedonia',
    'MADAGASCAR' => 'Madagascar',
    'MALAWI' => 'Malawi',
    'MALAYSIA' => 'Malaysia',
    'MALDIVES' => 'Maldives',
    'MALI' => 'Mali',
    'MALTA' => 'Malta',
    'MARSHALL ISLANDS' => '',
    'MARTINIQUE' => 'Martinique',
    'MAURITANIA' => 'Mauritania',
    'MAURITIUS' => 'Mauritius',
    'MAYOTTE' => 'Mayotte',
    'MEXICO' => 'Mexico',
    'MICRONESIA' => '',
    'MOLDOVA' => 'Moldova',
    'MONACO' => 'Monaco',
    'MONGOLIA' => 'Mongolia',
    'MONTENEGRO' => 'Montenegro',
    'MONTSERRAT' => 'Montserrat',
    'MOROCCO' => 'Morocco',
    'MOZAMBIQUE' => 'Mozambique',
    'MYANMAR' => 'Myanmar',
    'NAMIBIA' => 'Namibia',
    'NAURU' => 'Nauru',
    'NEPAL' => 'Nepal',
    'NETHERLANDS' => 'Netherlands',
    'NETHERLANDS ANTILLES' => 'Netherlands Antilles',
    'THE NETHERLANDS' => 'Netherlands',
    'NEW CALEDONIA' => 'New Caledonia',
    'NEW ZEALAND' => 'New Zealand',
    'NICARAGUA' => 'Nicaragua',
    'NIGER' => 'Niger',
    'NIGERIA' => 'Nigeria',
    'NIUE' => 'Niue',
    'NORFOLK ISLAND' => 'Norfolk Island',
    'NORTHERN MARIANA ISLANDS' => '',
    'NORWAY' => 'Norway',
    'OMAN' => 'Oman',
    'PAKISTAN' => 'Pakistan',
    'PALAU' => '',
    'PALESTINIAN TERRITORY' => 'Palestinian Territory, Occupied',
    'PANAMA' => 'Panama',
    'PAPUA NEW GUINEA' => 'Papua New Guinea',
    'PARAGUAY' => 'Paraguay',
    'PERU' => 'Peru',
    'PHILIPPINES' => 'Philippines',
    'PITCAIRN' => 'Pitcairn',
    'POLAND' => 'Poland',
    'PORTUGAL' => 'Portugal',
    'PUERTO RICO' => 'Puerto Rico',
    'QATAR' => 'Qatar',
    'REUNION' => 'Reunion',
    'ROMANIA' => 'Romania',
    'RUSSIA' => 'Russia',
    'RUSSIAN FEDERATION' => 'Russian Federation',
    'RWANDA' => 'Rwanda',
    'SAINT BARTHÉLEMY' => 'Saint Barthélemy',
    'SAINT HELENA' => 'Saint Helena, Ascension and Tristan da Cunha',
    'SAINT KITTS AND NEVIS' => 'Saint Kitts and Nevis',
    'SAINT LUCIA' => 'Saint Lucia',
    'SAINT MARTIN (FRENCH PART)' => 'Saint Martin (French part)',
    'SAINT PIERRE AND MIQUELON' => 'Saint Pierre and Miquelon',
    'SAINT VINCENT AND THE GRENADINES' => 'Saint Vincent and the Grenadines',
    'SAMOA' => 'Samoa',
    'SAN MARINO' => 'San Marino',
    'SAO TOME AND PRINCIPE' => 'Sao Tome and Principe',
    'SAUDI ARABIA' => 'Saudi Arabia',
    'SENEGAL' => 'Senegal',
    'SERBIA' => 'Serbia',
    'SEYCHELLES' => 'Seychelles',
    'SIERRA LEONE' => 'Sierra Leone',
    'SINGAPORE' => 'Singapore',
    'SLOVAKIA' => 'Slovakia',
    'SLOVENIA' => 'Slovenia',
    'SOLOMON ISLANDS' => 'Solomon Islands',
    'SOMALIA' => 'Somalia',
    'SOUTH AFRICA' => 'South Africa',
    'SOUTH GEORGIA AND THE SOUTH SANDWICH ISLANDS' => 'South Georgia and the South Sandwich Islands',
    'SPAIN' => 'Spain',
    'SRI LANKA' => 'Sri Lanka',
    'SUDAN' => 'Sudan',
    'SURINAME' => 'Suriname',
    'SVALBARD AND JAN MAYEN' => 'Svalbard and Jan Mayen',
    'SWAZILAND' => 'Swaziland',
    'SWEDEN' => 'Sweden',
    'SWITZERLAND' => 'Switzerland',
    'SYRIA' => 'Syria',
    'SYRIAN ARAB REPUBL' => 'Syrian Arab Republic',
    'TAIWAN' => 'Taiwan',
    'TAJIKISTAN' => 'Tajikistan',
    'TANZANIA' => 'Tanzania',
    'THAILAND' => 'Thailand',
    'TIMOR-LESTE' => 'Timor-Leste',
    'TOGO' => 'Togo',
    'TOKELAU' => 'Tokelau',
    'TONGA' => 'Tonga',
    'TRINIDAD AND TOBAGO' => 'Trinidad and Tobago',
    'TRINIDAD' => 'Trinidad and Tobago',
    'TUNISIA' => 'Tunisia',
    'TURKEY' => 'Turkey',
    'TURKMENISTAN' => 'Turkmenistan',
    'TURKS AND CAICOS ISLANDS' => 'Turks and Caicos Islands',
    'TUVALU' => 'Tuvalu',
    'U.S. VIRGIN ISLANDS' => 'U.S. Virgin Islands',
    'UGANDA' => 'Uganda',
    'UKRAINE' => 'Ukraine',
    'UNITED ARAB EMIRATES' => 'United Arab Emirates',
    'UNITED ARAB EMIRAT' => 'United Arab Emirates',
    'UAE' => 'United Arab Emirates',
    'UNITED KINGDOM' => 'United Kingdom',
    'UK' => 'United Kingdom',
    'UNITED STATES' => 'United States',
    'UNITED STATES MINOR OUTLYING ISLANDS' => '',
    'UNITED STATES MINO' => '',
    'URUGUAY' => 'Uruguay',
    'UZBEKISTAN' => 'Uzbekistan',
    'VANUATU' => 'Vanuatu',
    'VENEZUELA' => 'Venezuela',
    'VIETNAM' => 'Vietnam',
    'WALLIS AND FUTUNA' => 'Wallis and Futuna',
    'WESTERN SAHARA' => 'Western Sahara',
    'YEMEN' => 'Yemen',
    'YUGOSLAVIA' => 'Yugoslavia',
    'ZAMBIA' => 'Zambia',
    'ZIMBABWE' => 'Zimbabwe',
  );

  /**
   * Canada Silverpop to Salesorce Abbrevation.
   */
  public $canadaAbbreviation = array(
    "ALBERTA"                   => "AB",
    "BRITISH COLUMBIA"          => "BC",
    "MANITOBA"                  => "MB",
    "NEW BRUNSWICK"             => "NB",
    "NEWFOUNDLAND AND LABRADOR" => "NL",
    "NORTHWEST TERRITORIES"     => "NT",
    "NOVA SCOTIA"               => "NS",
    "NUNAVUT"                   => "NU",
    "ONTARIO"                   => "ON",
    "PRINCE EDWARD ISLAND"      => "PE",
    "QUEBEC"                    => "QC",
    "SASKATCHEWAN"              => "SK",
    "YUKON"                     => "YT",
  );

  /**
   * Post data to Ringlead (Salesforce).
   *
   * @param array $silverpopData
   *   Silverpop object.
   */
  public function postToRingLead($silverpopData) {
    $salesforce = array();

    // Convert Silverpop fields to Salesforce fields.
    foreach ($silverpopData as $silverpop_field => $silverpop_value) {
      if (isset($this->fieldNameMapping[$silverpop_field])) {
        $salesforce[$this->fieldNameMapping[$silverpop_field]] = $this->mapValues($silverpop_field, $silverpop_value);
      }
    }

    // Convert Silverpop Address to Salesforce.
    if (isset($silverpopData['Address 1'])) {
      // Only add address 2 to address 1 if it doesn't have the same value in
      // both fields.
      if (isset($silverpopData['Address 2']) && strpos($silverpopData['Address 1'], $silverpopData['Address 2']) === false) {
        $salesforce['Street'] = $silverpopData['Address 1'] . " " . $silverpopData['Address 2'];
      }
      else {
        $salesforce['Street'] = $silverpopData['Address 1'];
      }
    }

    // PP OEM form
    if (isset($silverpopData['form id']) && $silverpopData['form id'] == 'PP_OEM Magazine Signup Form') {
     // #1097 - adding separate fields for Digital Edition and Print Magazine
     // #1097 - Check for Print Requested
      if ($silverpopData['PP OEM Mag Requested Version'] == 'Qualified active') { // NL PP OEM Digital Edition
        // Only allow print if they are in U.S.
        if (isset($silverpopData['Country']) && (strtoupper($silverpopData['Country']) == 'UNITED STATES')) {
          $salesforce['PP_OEM_Classification__c'] = 'Qualified active';
          $salesforce['PP_OEM_Mag_Requested_Version__c'] = 'Print';
        }
        else {
          $salesforce['PP_OEM_Classification__c'] = 'Qualified reserve';
          $salesforce['PP_OEM_Mag_Requested_Version__c'] = 'Digital';
        }
      }

      // #1097 - Check for a digital edition request (country not important)
      if ($silverpopData['NL PP OEM Digital Edition'] == 'Yes') {
         $salesforce['PP_OEM_Digital_Edition__c'] == 'Yes';
      }
      else {
         $salesforce['PP_OEM_Digital_Edition__c'] == 'No';
      }

    }

    // Url-ify the data for the POST
    $fields_string = '';
    foreach($salesforce as $key => $value) {
      $fields_string .= $key.'='.$value.'&';
    }
    rtrim($fields_string,'&');

    // Open connection.
    $ch = curl_init();

    // Set the url, number of POST vars, POST data.
    curl_setopt($ch,CURLOPT_URL, $this->ringLeadUrl);
    curl_setopt($ch,CURLOPT_POST, count($salesforce));
    curl_setopt($ch,CURLOPT_POSTFIELDS, $fields_string);
    curl_setopt($ch,CURLOPT_RETURNTRANSFER, 1);

    // Execute post.
    $result = curl_exec($ch);

    // Close connection.
    curl_close($ch);

  }

  /**
   * Map the field values from Silverpop to Salesforce.
   *
   * @param string $silverpop_field
   *   Silverpop field name.
   * @param string $value
   *   Silverpop value.
   *
   * @return string $value
   *   Mapped values.
   */
  public function mapValues($silverpop_field, $value) {
    switch ($silverpop_field) {
      case 'PW HCP Industry':
        $value = isset($this->pwIndustry[$value]) ? $this->pwIndustry[$value] : '';
        break;

      case 'PW HCP Contract Packaging':
        $value = isset($this->pwContractPackagingMapping[$value]) ? $this->pwContractPackagingMapping[$value] : '';
        break;

      case 'PW HCP Job Duties':
        $value = isset($this->pwJobDutiesMapping[$value]) ? $this->pwJobDutiesMapping[$value] : '';
        break;

      case 'AW Industry':
        $value = isset($this->awIndustryMapping[$value]) ? $this->awIndustryMapping[$value] : '';
        break;

      case 'AW Automation Type':
        $value = isset($this->automationTypeMapping[$value]) ? $this->automationTypeMapping[$value] : '';
        break;

      case 'State':
        // if Canadian provinces, need to convert to two digit abbreviation
        // http://canadaonline.about.com/od/postalservices/a/abbreviations-provinces-canada.htm
        if (isset($this->canadaAbbreviation[strtoupper($value)])) {
          $value = $this->canadaAbbreviation[strtoupper($value)];
        }
        break;

    }

    return $this->prepareValue($value);
  }

  /**
   * Url Encode and prepares the value.
   *
   * @param string $value
   *   The value that needs to be prepared.
   *
   * @param string $value
   *   The urlencoded value.
   */
  public function prepareValue($value) {
    return urlencode($value);
  }

}
