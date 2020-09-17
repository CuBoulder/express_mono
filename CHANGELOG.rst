Changelog
=========

All notable changes to this project will be documented in this file.

The format is based on `Keep a Changelog`__, and this project adheres to `Semantic Versioning`__.

v4.3.2 (2020-09-17)
------------

Fixed
~~~~~~~
- Revert Google Tag Manager contrib update. Resolves #707.

v4.3.1 (2020-09-10)
------------

Changed
~~~~~~~
- Replace poor language choices 'master/slave'; 'whitelist/blacklist'.

- Checking to see if alerts xml is valid. Resolves #677.

- Adding back in settings option for sidebars. resolves #517.

- Updated contributed modules

- We now test using our modified Drupal core


Deprecated
~~~~~~~
- All themes are responsive. Fixed width sites have been deprecated. Removed toggle for responsive settings.


Fixed
~~~~~~~
- Fixing notice if a block did not have a bid value. Resolves #696.

- Article slider links are now the correct color. Removed extra/empty links. Resolves #548.



v4.3.0 (2020-04-21)
------------

Added
~~~~~~~
- Adding a setting to hide the subnavigation on mobile devices. Resolves #344.

- Add masquerade module.


Changed
~~~~~~~
- Removing hard coded array of feature names to ignore when overridden. If a feature is expected to be overridden 'settings[can_be_overridden] = 1' should be added to its .info file.

- cu_googleanalytics 'can_be_overridden'.

- cu_home_page 'can_be_overridden'.

- cu_linkchecker 'can_be_overridden'.

- Fixing issue where the excluded blocks in block wrapper weren't set correctly in the last update. Resolves #564.

- Adjusted user_external_invite_user_role_delete() to search for correct variable and remove content_editor rid.

- Allow multiple bylines in articles. resolves #554.

- Update Drupal core version.


Fixed
~~~~~
- Previous and next icons in datepicker no display correctly.

- Horizontal scroll bar no longer displays with the responsive table shortcode on browsers running on Windows. Resolves #530.

- Fix: Article redirects were ignoring query parameters attached to a url. resolves #496.


Removed
~~~~~~~
- Removing deprecated content editor role.

- Removed unused function with its broken link. Resolves #581.


v4.2.2 (2020-05-14)
------------

Added
~~~~~
- Adding large search box block.


Changed
~~~~~~~
- Improving active states for secondary navigation.

- Improve module uninstall process to remove associated roles as well.


Fixed
~~~~~~~
- Fixing issue where some block titles weren't styled correctly.


Removed
~~~~~~~
- Removing deprecated content editor role.


v4.2.1 (2020-04-21)
------------

This release reverts a PR with a bug in it and resolves an increase in logging.

Fixed
~~~~~~~
- New notice in cu_shortcodes module

- External Article Links not working properly


v4.2.0 (2020-04-15)
------------

This release adds site affiliation and improves our visibility into the service.

Added
~~~~~~~
- Setting and enabling site affiliation. Resolves #422.

- Added code to cu_core.install to check for overridden features so that they are displayed as warnings in the /admin/reports/status page.

- Adding fac staff calendar filter to available filters.

- Add Alan Cole and Brooke Stevens to CU Users.

- Add status check for secure perms and mixed authentication mode.


Changed
~~~~~~~
- Pin browser version for automated testing.

- Combine scenarios to increase test speed.

- Can now add a link to an anchor on the same page using the pattern #<anchor_name>

Fixed
~~~~~~~
- Allow users with form_submitter role to be edited and/or deleted. Resolves #244.

- Fixing issue where external article link did not keep url query parameters when redirecting. Resolves #496.

- Fixing issue where hero style images placed in the wysiwyg field would extend outside the edges of the page on the Shadow theme when responsiveness was disabled. Resolves #490.

- Fixing issue where urls with query parameters would not work with rss feeds. Resolves #476.

Deprecated
~~~~~~~
- Disable and uninstall old tracking pixel modules. Resolves #462.


v4.1.4 (2020-02-12)
------------

This release add content types to the default sitemap and removes configuration that had no impact.

Changed
~~~~~~~
- Adding photo galleries, collection items, and section pages to xml site map. #351

- Removing configuration for Block Icon Color. #434


v4.1.3 (2020-01-14)
------------

This release resolves some display bugs.

Added
~~~~~
- Adding Pantheon Advanced Page Cache and d8cache modules.

Changed
~~~~~~~
- Adding test for mega menu rendering. #450

- Fixing issue where block designer theme previews did not show background colors. #445

- Updated Webform from 4.20 to 4.21. #426

- Replacing & with and in affiliation names. #235

Fixed
~~~~~~

- Fixed issue where edit_my_content users could not edit person node they owned. #467

Removed
~~~~~

- Remove testing on PHP 7.1. #460

- Remove admin permission for a user; stop adding them to new sites.

- Removing original read more link on some article view modes. #431

- Remove logging messages during normal RAVE state. #425

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
- Add a Github Action to create a Changelog artifact release branches are opened. #333

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

- Remove blocked users from the Atlas statistics user report. #195

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
