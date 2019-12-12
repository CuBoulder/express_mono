Changelog
=========

All notable changes to this project will be documented in this file.

The format is based on `Keep a Changelog`__, and this project adheres to `Semantic Versioning`__.

v4.1.2 (2019-12-10)
------------

This release adds the 'Save and Add Another' feature to many content types, updated contrib modules, and resolved some CSS bugs.

Added
~~~~~~~

- 'Save and Add Another' functionality added to select content types. #115

Changed
~~~~~~~
- Remove Site Status Section from admin/settings.

- Rebuild secure permissions after removing perms for express site status.

- Adding comments about site affiliation fields, display. #413

- Fixing issue where campus logo would not display at the correct aspect ration in some clients. #393

- Fixed issue where buttons in vertical tabs did not have correct color. #401

- Update webform from 7.x-4.19 to 7.x-4.20. #374

- Updated file_entity from 7.x-2.25 to 7.x-2.27. #374

- Updated google_tag from 7.x-1.4 to 7.x-1.6. #374

- Update link from 7.x-1.6 to 7.x-1.7. #374

- Update captcha from 7.x-1.5 to 7.x-1.6. #374

- Update inline_entity_form from 7.x-1.8 to 7.x-1.9. #374

- Updated unpublished_404 from 7.x-1.1 to 7.x-1.2. #374

- Update field_collection from 7.x-1.0-beta13 to 7.x-1.1. #374

- Update and patch simplesamlphp_auth module.

- Updating variable sets for simplesamlphp_auth_user_name and simplesamlphp_auth_unique_id. 

- Updating gemfiles #326

- Sorting social link type options alphabetically #357

- Updated text for bundle request email. #375

- Replacing '&' with 'and' in affiliation names. #235

Fixed
~~~~~
- Changelog is generated correctly. 

- Fixing issue where administrators couldn't edit user roles #114.

- Fixing flexbox display of issue grids #326.

Removed
~~~~~~~
- Remove express help module. #361

- Removing zengrids from publication bundle #326

v4.1.1 (2019-11-12)
------------

This update resolves several visual regressions and begins removing unused or broken code.

Added
~~~~~
- Add a Github Action to create a Changelog artifact release branches are opened. Resolves #333.

Changed
~~~~~
- Fixing issue where image styles were not getting flushed properly #328.

- Setting a dependency for cu_help module #324.

- Update README to better reflect reality of the profile.

- Updating Helpscout beacon to version 2.0 #263.

- Updating newsletter design with new website standards #207.

- Update PHP 7.1 patch version and add PHP 7.2.


Fixed
~~~~~
- Fixing issue where share on twitter link was not creating a tweet #306.

- Adding a background color class for slider style 4 to set link colors correctly #334.

- Fixing issue where social links reference would error if social links were not enabled #343.

- Fixing issue where social links have underlines if nested in multiple background color classes #314.

- Fixing issue where hero image styles where not positioned properly when page layout was set to feature layout #312.

- Fixing notice of missing variable for intro region #325.

Deprecated
~~~~~

- Disabling and uninstall express_help module #324.

Removed
~~~~~

- Remove developer role from devs who are gone.

- Removing redis dependency from pantheon_hosting.info.

- Remove blocked users from the Atlas statistics user report. Resolves #195.

- Remove debug module Stage File Proxy.

v4.1.0 (2019-10-08)
-------------------

This update adds support for Pardot (Salesforce lead generation) forms, brings the Slate bundle into the core profile, and resolves several CSS bugs.

Added
~~~~~
- Add Pardot embed template module #300.

- Adding slate bundle #62.

Changed
~~~~~
- Removing message about unsetting progress bar in webform node creation #269.

- Move and improve AB tests.

- Update login and user modules to work with SAML.

- Remove features that duplicate tests.

Fixed
~~~~~
- Buttons in slider content gets the wrong text color #258.

- Teaser image display at the wrong aspect ratio if a link wasn't added #305.

- Button text color in card style content grids are the wrong color #292.

Removed
~~~~~
- Remove drupal-org make files.

- Remove developer modules.

v4.0.1 (2019-09-19)
------

Added
~~~~~
- Add developers Jeremy Sparks, Michael Bolei, Christina Morris.

- Added digital campaign and A/B test bundles.

Changed
~~~~~
- Adding cu_saml module to pantheon_hosting dependencies list.

- Updating dependencies and module_disable() in pantheon_hosting module.

- Update module wysiwyg to 7x-2.6.

- Update HTML Title to 7.x-1.5.

Fixed
~~~~~
- Fixing issue where form fields on dark backgrounds might be unreadable #267.

- Fixing issue where article read more link wasn't rendering correctly when part of an issue #227.

- Fix broken test that tested EditOnly access to Block Row blocks.

- Making sure content grid link colors are correct #232.

- Preventing links with fixed colors from inheriting underlines, reducing transparency to help accessibility #232.

- Fixing a spacing issue on teaser display where linked images would add additional padding #232.

- Fixing issue where content grid links would be wrong colors if placed in block sections #232.

- Explicitly telling .travis.yml to initialize mysql.

- Fixing block designer background classes #239.

- Fixing color nesting issues #239.

- Fixing issue where block designer blocks did not the the correct link colors #239.

- Fixing issue where semitransparent content background was fully opaque #234.

- Fixed link to project URL for live chat.

v4.0.0 (2019-08-07)
-----------------

This update begins the process of adding what were separate code bundles back into the core profile, adds the mega menu bundle, and includes various bug fixes and improvements.

Added
~~~~~
- Add mega menu bundle. #48

- Add custom logo to sticky menus. #3

- Add ability to choose brand bar color. #2

Changed
~~~~~
- Consolidate code into a single repository: Campus News, Class Notes, Livestream, Content Sequence, Newsletter, Livechat, Publications, Chemistry Titles, Custom Logo, Responsive Visibility, Section Page, Collections, Video Hero Unit, Localist.

- Make changes to support cloud hosting.

- Increased Form bundle test coverage.

- Setting GTM ID, enabling google_tag on existing sites. #142

Deprecated
~~~~~
- Add instructions and deprecated label to old fields. #3

Removed
~~~~~
- Remove Atlas code UI. #113

- Remove developers from install profile. #221

Fixed
~~~~~
- Logo did not size properly in Firefox. #212

- Test content images did not load. #163

- Correct color of affiliation text/link on black site name banners. #188

- Correct content sequence formating with italics. #214

- Hide text description that is no supposed to appear. #118

- Center 'more' link on campus news grid. #162

- Correct footer link color on simple newsletter theme. #164

- Collection terms sort predictably. #166

- Correct expandable link colors on dark backgrounds. #10

- Correct alignment of hero content at various browser widths. #149

- Improve contrast of block designer outline on dark backgrounds. #158

- User 1 cannot access bundle configuration screens. #145

- Related article calculation is incorrect. #1

- Drupal blocks could not be configured. #121

- Correct section page content on mobile displays. #150

- Some themes have too much padding at wide widths. #151

- Page title had too much horizontal padding on mobile displays. #152

- Correct blocks display with offset icons. #106

- Correct height of lighttheme page titles. #157

- Improve nesting of background color classes. #6

- Fixing notice if a homepage is set to a path that is not a node. #86

- Correct 'site name' line height on non-front pages. #9

- Correct form fields display on dark backgrounds. #8

- Display breadcrumbs when a feature image was set. #7

- Allow teaser content grid to display short text content. #4

- Correct link color when the background color for the region is not correct. #5

Security
~~~~~
- Update Drupal contributed modules. #116


__ https://keepachangelog.com/en/1.0.0/
__ https://semver.org/spec/v2.0.0.html