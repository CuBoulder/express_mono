<?php

function cu_campus_map_bundle_data($location = NULL) {
  $locations = array(
    'ADEN' => array(
      'label' => 'Aden Hall',
      'marker' => '193791',
    ),
    'ALUM' => array(
      'label' => 'Koenig Alumni Center',
      'marker' => '193918',
    ),
    'ANDS' => array(
      'label' => 'Andrews Hall',
      'marker' => '193793',
    ),
    'ARCE' => array(
      'label' => 'Administrative and Research Center',
      'marker' => '193792',
    ),
    'ARL' => array(
      'label' => 'Astrophysical Research Lab (Formerly CASA)',
      'marker' => '193819',
    ),
    'ARMR' => array(
      'label' => 'Armory',
      'marker' => '193794',
    ),
    'ARNT' => array(
      'label' => 'Arnett Hall',
      'marker' => '193798',
    ),
    'ATCT' => array(
      'label' => 'Athens Court',
      'marker' => '193799',
    ),
    'ATHN' => array(
      'label' => 'Athens North Court',
      'marker' => '193800',
    ),
    'ATLS' => array(
      'label' => 'Roser ATLAS Center',
      'marker' => '193967',
    ),
    'BCAP' => array(
      'label' => 'Bear Creek Apartments at Williams Village',
      'marker' => '193805',
    ),
    'BESC' => array(
      'label' => 'Benson Earth Sciences',
      'marker' => '222147',
    ),
    'BIOT' => array(
      'label' => 'Jennie Smoly Caruthers Biotec Building',
      'marker' => '193911',
    ),
    'BKER' => array(
      'label' => 'Baker Hall',
      'marker' => '193803',
    ),
    'BRKT' => array(
      'label' => 'Brackett Hall',
      'marker' => '193808',
    ),
    'BUCK' => array(
      'label' => 'Buckingham Hall',
      'marker' => '193810',
    ),
    'C4C' => array(
      'label' => 'Center for Community',
      'marker' => '193820',
    ),
    'CARL' => array(
      'label' => 'Carlson Gymnasium',
      'marker' => '193818',
    ),
    'CASA' => array(
      'label' => 'Center for Asian Studies',
      'marker' => '226113',
    ),
    'CASE' => array(
      'label' => 'The Center for Academic Success and Engagement (CASE)',
      'marker' => '347439',
    ),
    'CEDU' => array(
      'label' => 'Continuing Education',
      'marker' => '193828',
    ),
    'CHEM' => array(
      'label' => 'Cristol Chemistry and Biochemistry',
      'marker' => '193831',
    ),
    'CHEY' => array(
      'label' => 'Cheyenne Arapaho Hall',
      'marker' => '193823',
    ),
    'CHMP' => array(
      'label' => 'Champion Center',
      'marker' => '193821',
    ),
    'CINC' => array(
      'label' => 'Center for Innovation & Creativity',
      'marker' => '204895',
    ),
    'CIRE' => array(
      'label' => 'Cooperative Institute for Research in Environmental Sciences (CIRES)',
      'marker' => '193829',
    ),
    'CKRL' => array(
      'label' => 'Cockerell Hall',
      'marker' => '193826',
    ),
    'CLRE' => array(
      'label' => 'Clare Small Arts and Sciences',
      'marker' => '193824',
    ),
    'CLUB' => array(
      'label' => 'University Club',
      'marker' => '193988',
    ),
    'COMP' => array(
      'label' => 'Computing Center',
      'marker' => '193827',
    ),
    'COTT' => array(
      'label' => 'Gates Woodruff Women\'s Studies Cottage',
      'marker' => '193875',
    ),
    'CROS' => array(
      'label' => 'Crosman Hall',
      'marker' => '193832',
    ),
    'DACR' => array(
      'label' => 'Children\'s Center',
      'marker' => '193867',
    ),
    'DALW' => array(
      'label' => 'Dal Ward Athletic Center',
      'marker' => '193833',
    ),
    'DDW' => array(
      'label' => 'Duane D-Wing',
      'marker' => '193840',
    ),
    'DEN' => array(
      'label' => 'Denison Arts and Sciences',
      'marker' => '193838',
    ),
    'DLC' => array(
      'label' => 'Discovery Learning Center',
      'marker' => '193839',
    ),
    'DLYT' => array(
      'label' => 'Darley North',
      'marker' => '193836',
    ),
    'DLYT' => array(
      'label' => 'Darly South',
      'marker' => '193837',
    ),
    'DUAN' => array(
      'label' => 'Duane Physics and Astrophysics',
      'marker' => '193841',
    ),
    'EC' => array(
      'label' => 'Engineering Center',
      'marker' => '193854',
    ),
    'ECAE' => array(
      'label' => 'Aerospace Engineering Wing',
      'marker' => '193857',
    ),
    'ECCE' => array(
      'label' => 'Civil Engineering',
      'marker' => '193856',
    ),
    'ECCS' => array(
      'label' => 'Computer Science Wing',
      'marker' => '193860',
    ),
    'ECEE' => array(
      'label' => 'Electrical Engineering Wing',
      'marker' => '193858',
    ),
    'ECME' => array(
      'label' => 'Mechanical Engineering Wing',
      'marker' => '193859',
    ),
    'ECON' => array(
      'label' => 'Economics',
      'marker' => '193844',
    ),
    'EDUC' => array(
      'label' => 'Education',
      'marker' => '193852',
    ),
    'EHSC' => array(
      'label' => 'Environmental Health and Safety Center',
      'marker' => '193862',
    ),
    'EKLC' => array(
      'label' => 'Ekeley Science',
      'marker' => '193853',
    ),
    'ENVD' => array(
      'label' => 'Environmental Design',
      'marker' => '193861',
    ),
    'EVNT' => array(
      'label' => 'CU Events Center',
      'marker' => '199650',
    ),
    'FACT1' => array(
      'label' => 'Faculty-Staff Court Housing',
      'marker' => '193866',
    ),
    'FH' => array(
      'label' => 'Balch Fieldhouse',
      'marker' => '193804',
    ),
    'FISK' => array(
      'label' => 'Fiske Planetarium and Science Center',
      'marker' => '193870',
    ),
    'FLMG' => array(
      'label' => 'Fleming Building',
      'marker' => '193871',
    ),
    'FRND' => array(
      'label' => 'Farrand Hall',
      'marker' => '193869',
    ),
    'GH-3' => array(
      'label' => 'Research Park Greenhouse',
      'marker' => '193966',
    ),
    'GOLD' => array(
      'label' => 'Gold Biosciences Building',
      'marker' => '193876',
    ),
    'GROC' => array(
      'label' => 'Grounds and Recycling Operations Center',
      'marker' => '206140',
    ),
    'GUGG' => array(
      'label' => 'Guggenheim Geography',
      'marker' => '193877',
    ),
    'GVAS' => array(
      'label' => 'Center for Native American & Indigenous studies (CNAIS)',
      'marker' => '268233',
    ),
    'HALE' => array(
      'label' => 'Hale Science',
      'marker' => '193879',
    ),
    'HEND' => array(
      'label' => 'Museum of Natural History (Henderson)',
      'marker' => '193940',
    ),
    'HLET' => array(
      'label' => 'Hallett Hall',
      'marker' => '193880',
    ),
    'HLMS' => array(
      'label' => 'Hellems Arts and Sciences',
      'marker' => '193881',
    ),
    'HSMC' => array(
      'label' => 'Housing System Maintenance Center',
      'marker' => '193883',
    ),
    'HSSC' => array(
      'label' => 'Housing System Service Center',
      'marker' => '193884',
    ),
    'HUMN' => array(
      'label' => 'Eaton Humanities',
      'marker' => '193885',
    ),
    'IB10' => array(
      'label' => 'Institute of Behavioral Science No. 10',
      'marker' => '193907',
    ),
    'IBG' => array(
      'label' => 'Institute for Behavioral Genetics',
      'marker' => '193896',
    ),
    'IBS' => array(
      'label' => 'Institute of Behavioral Science',
      'marker' => '193898',
    ),
    'IBS9' => array(
      'label' => 'Institute of Behavioral Science No. 09',
      'marker' => '193906',
    ),
    'IEC' => array(
      'label' => 'International English Center',
      'marker' => '193909',
    ),
    'IPRC' => array(
      'label' => 'Indoor Practice Facility',
      'marker' => '204891',
    ),
    'ITLL' => array(
      'label' => 'Integrated Teaching and Learning Laboratory',
      'marker' => '193908',
    ),
    'JILA' => array(
      'label' => 'JILA',
      'marker' => '193910',
    ),
    'KOBL' => array(
      'label' => 'Koelbel Building: Leeds School of Business',
      'marker' => '193917',
    ),
    'KTCH' => array(
      'label' => 'Ketchum Arts and Sciences',
      'marker' => '193913',
    ),
    'LESS' => array(
      'label' => 'Lesser House',
      'marker' => '193920',
    ),
    'LIBR' => array(
      'label' => 'Norlin Library',
      'marker' => '193942',
    ),
    'LIBY' => array(
      'label' => 'Libby Hall',
      'marker' => '193921',
    ),
    'LITR' => array(
      'label' => 'Research Laboratory No. 1, Litman',
      'marker' => '193962',
    ),
    'LRVN' => array(
      'label' => 'Kittredge Central',
      'marker' => '193914',
    ),
    'LSRL' => array(
      'label' => 'Research Laboratory No. 4, Life Science',
      'marker' => '193964',
    ),
    'LSTR' => array(
      'label' => 'LASP Space Technology Research Center',
      'marker' => '193919',
    ),
    'MAIN' => array(
      'label' => 'Old Main',
      'marker' => '193948',
    ),
    'MATH' => array(
      'label' => 'Mathematics Building',
      'marker' => '193928',
    ),
    'MCKY' => array(
      'label' => 'Macky Auditorium',
      'marker' => '193924',
    ),
    'MCOL' => array(
      'label' => 'Bruce Curtis Building (Museum Collections)',
      'marker' => '193809',
    ),
    'MKNA' => array(
      'label' => 'McKenna Languages',
      'marker' => '193936',
    ),
    'MRCT' => array(
      'label' => 'Marine Court',
      'marker' => '193926',
    ),
    'MSSC' => array(
      'label' => 'Research Laboratory No. 6, Marine Street Science Center',
      'marker' => '193965',
    ),
    'MUEN' => array(
      'label' => 'Muenzinger Psychology',
      'marker' => '193937',
    ),
    'MUS' => array(
      'label' => 'Imig Music',
      'marker' => '193889',
    ),
    'NIWOT' => array(
      'label' => 'Kittredge West Hall',
      'marker' => '193916',
    ),
    'NTCT' => array(
      'label' => 'Newton Court',
      'marker' => '193941',
    ),
    'OB1' => array(
      'label' => 'Arts & Sciences Office Building 1',
      'marker' => '224596',
    ),
    'OBSV' => array(
      'label' => 'Sommers-Bausch Observatory',
      'marker' => '193973',
    ),
    'PDPS' => array(
      'label' => 'Police and Parking Services',
      'marker' => '206032',
    ),
    'PFDC' => array(
      'label' => 'Page Foundation Center',
      'marker' => '205907',
    ),
    'PFPS' => array(
      'label' => 'Athletics Practice Field',
      'marker' => '218691',
    ),
    'PORT' => array(
      'label' => 'Porter Biosciences',
      'marker' => '193952',
    ),
    'POTT' => array(
      'label' => 'Potts Field',
      'marker' => '218696',
    ),
    'POWR' => array(
      'label' => 'Power House',
      'marker' => '203742',
    ),
    'RAMY' => array(
      'label' => 'Ramaley Biology',
      'marker' => '193957',
    ),
    'REC' => array(
      'label' => 'Student Recreation Center',
      'marker' => '193980',
    ),
    'REED' => array(
      'label' => 'Reed Hall',
      'marker' => '193960',
    ),
    'RGNT' => array(
      'label' => 'Regent Administrative Center',
      'marker' => '193961',
    ),
    'RL2' => array(
      'label' => 'Research Laboratory No. 2, RL2',
      'marker' => '193963',
    ),
    'SEEC' => array(
      'label' => 'Sustainability, Energy and Environment Community (SEEC)',
      'marker' => '193923',
    ),
    'SEEL' => array(
      'label' => 'Sustainability, Energy and Environment Laboratory (SEEL)',
      'marker' => '204809',
    ),
    'SLHS' => array(
      'label' => 'Speech, Language, and Hearing Sciences',
      'marker' => '193976',
    ),
    'SLL' => array(
      'label' => 'Science Learning Laboratory',
      'marker' => '193969',
    ),
    'SMCT' => array(
      'label' => 'Smiley Court',
      'marker' => '193971',
    ),
    'SMTH' => array(
      'label' => 'Smith Hall',
      'marker' => '193972',
    ),
    'SPSC' => array(
      'label' => 'Space Science Building',
      'marker' => '193975',
    ),
    'STAD' => array(
      'label' => 'Folsom Field & Stadium',
      'marker' => '193872',
    ),
    'STNE' => array(
      'label' => 'Stearns East',
      'marker' => '204615',
    ),
    'STNW' => array(
      'label' => 'Stearns West',
      'marker' => '204614',
    ),
    'STRN' => array(
      'label' => 'Stearns Commons',
      'marker' => '193979',
    ),
    'STTB' => array(
      'label' => 'Stadium Ticket Building',
      'marker' => '193977',
    ),
    'SWLL' => array(
      'label' => 'Sewall Hall',
      'marker' => '193970',
    ),
    'TB01' => array(
      'label' => 'Temporary Building No. 1',
      'marker' => '193983',
    ),
    'TB19' => array(
      'label' => 'University Administrative Center Annex',
      'marker' => '193987',
    ),
    'TB82' => array(
      'label' => 'Temporary Building 82',
      'marker' => '224591',
    ),
    'THTR' => array(
      'label' => 'University Theatre',
      'marker' => '193994',
    ),
    'TLC' => array(
      'label' => 'Technology Learning Center',
      'marker' => '193981',
    ),
    'TRAN' => array(
      'label' => 'Transportation Center and Annex',
      'marker' => '203745',
    ),
    'UCTR' => array(
      'label' => 'University Administrative Center',
      'marker' => '193986',
    ),
    'UMC' => array(
      'label' => 'CU Book Store',
      'marker' => '193816',
    ),
    'UMC' => array(
      'label' => 'University Memorial Center (UMC)',
      'marker' => '222210',
    ),
    'VAC' => array(
      'label' => 'CU Art Museum',
      'marker' => '202075',
    ),
    'VAC' => array(
      'label' => 'Visual Arts Complex',
      'marker' => '193996',
    ),
    'W-BF' => array(
      'label' => 'Business Field',
      'marker' => '193811',
    ),
    'W-FR' => array(
      'label' => 'Franklin Field',
      'marker' => '218695',
    ),
    'W-GT' => array(
      'label' => 'Gamow Tower',
      'marker' => '193874',
    ),
    'W-KF' => array(
      'label' => 'Kittredge Field',
      'marker' => '218694',
    ),
    'W-MR' => array(
      'label' => 'Mary Rippon Theatre',
      'marker' => '193927',
    ),
    'W-PRF' => array(
      'label' => 'Prentup Field',
      'marker' => '218697',
    ),
    'W-TF' => array(
      'label' => 'Dalton Trumbo Fountain Court',
      'marker' => '193834',
    ),
    'WALN' => array(
      'label' => 'Distribution Center',
      'marker' => '206133',
    ),
    'WARD' => array(
      'label' => 'Wardenburg Student Health Center',
      'marker' => '205905',
    ),
    'WDBY' => array(
      'label' => 'Woodbury Arts and Sciences',
      'marker' => '194006',
    ),
    'WLAW' => array(
      'label' => 'Wolf Law',
      'marker' => '194001',
    ),
    'WLRD' => array(
      'label' => 'Willard Hall',
      'marker' => '194000',
    ),
    'WVC' => array(
      'label' => 'Village Center Dining and Community Commons',
      'marker' => '193835',
    ),
    'WVHP' => array(
      'label' => 'Williams Village Heating Plant',
      'marker' => '232151',
    ),
    'WVN' => array(
      'label' => 'Williams Village North',
      'marker' => '204893',
    ),
    'WVRC' => array(
      'label' => 'Williams Village Recreation Center',
      'marker' => '239752',
    ),
  );

  return $locations;
}
