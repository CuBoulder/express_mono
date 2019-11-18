Changelog
=========

All notable changes to this project will be documented in this file.

The format is based on `Keep a Changelog`__, and this project adheres to `Semantic Versioning`__.

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
- Add mega menu bundle. [#48](https://github.com/CuBoulder/express_mono/issues/48).

- Add custom logo to sticky menus. [#3](https://github.com/CuBoulder/express_mono/issues/3).

- Add ability to choose brand bar color. [#2](https://github.com/CuBoulder/express_mono/issues/2).

Changed
~~~~~
- Consolidate code into a single reposistory: Campus News, Class Notes, Livestream, Content Sequence, Newsletter, Livechat, Publications, Chemistry Titles, Custom Logo, Responsive Visibility, Section Page, Collections, Video Hero Unit, Localist.

- Make changes to support cloud hosting.

- Increased Form bundle test coverage.

- Setting GTM ID, enabling google_tag on existing sites. [#142](https://github.com/CuBoulder/express_mono/issues/142).

Deprecated
~~~~~
- Add instructions and deprecated label to old fields. [#3](https://github.com/CuBoulder/express_mono/issues/3).

Removed
~~~~~
- Remove Atlas code UI. [#113](https://github.com/CuBoulder/express_mono/issues/113).

- Remove developers from install profile. [#221](https://github.com/CuBoulder/express_mono/issues/221).

Fixed
~~~~~
- Logo did not size properly in Firefox. [#212](https://github.com/CuBoulder/express_mono/issues/212).

- Test content images did not load. [#163](https://github.com/CuBoulder/express_mono/issues/163).

- Correct color of affiliation text/link on black site name banners. [#188](https://github.com/CuBoulder/express_mono/issue/188s).

- Correct content sequence formating with italics. [#214](https://github.com/CuBoulder/express_mono/issues/214).

- Hide text description that is no supposed to appear. [#118](https://github.com/CuBoulder/express_mono/issues/118).

- Center 'more' link on campus news grid. [#162](https://github.com/CuBoulder/express_mono/issues/162).

- Correct footer link color on simple newsletter theme. [#164](https://github.com/CuBoulder/express_mono/issues/164).

- Collection terms sort predictably. [#166](https://github.com/CuBoulder/express_mono/issues/166).

- Correct expandable link colors on dark backgrounds. [#10](https://github.com/CuBoulder/express_mono/issues/10).

- Correct alignment of hero content at various browser widths. [#149](https://github.com/CuBoulder/express_mono/issues/149).

- Improve contrast of block designer outline on dark backgrounds. [#158](https://github.com/CuBoulder/express_mono/issues/158).

- User 1 cannot access bundle configuration screens. [#145](https://github.com/CuBoulder/express_mono/issues/145).

- Related article calculation is incorrect. [#1](https://github.com/CuBoulder/express_mono/issues/1).

- Drupal blocks could not be configured. [#121](https://github.com/CuBoulder/express_mono/issues/121).

- Correct section page content on mobile displays. [#150](https://github.com/CuBoulder/express_mono/issues/150).

- Some themes have too much padding at wide widths. [#151](https://github.com/CuBoulder/express_mono/issues/151).

- Page title had too much horizontal padding on mobile displays. [#152](https://github.com/CuBoulder/express_mono/issues/152).

- Correct blocks display with offset icons. [#106](https://github.com/CuBoulder/express_mono/issues/106).

- Correct height of lighttheme page titles. [#157](https://github.com/CuBoulder/express_mono/issues/157).

- Improve nesting of background color classes. [#6](https://github.com/CuBoulder/express_mono/issues/6).

- Fixing notice if a homepage is set to a path that is not a node. [#86](https://github.com/CuBoulder/express_mono/issues/86).

- Correct 'site name' line height on non-front pages. [#9](https://github.com/CuBoulder/express_mono/issues/9).

- Correct form fields display on dark backgrounds. [#8](https://github.com/CuBoulder/express_mono/issues/8).

- Display breadcrumbs when a feature image was set. [#7](https://github.com/CuBoulder/express_mono/issues/7).

- Allow teaser content grid to display short text content. [#4](https://github.com/CuBoulder/express_mono/issues/4).

- Correct link color when the background color for the region is not correct. [#5](https://github.com/CuBoulder/express_mon/5o/issues).

Security
~~~~~
- Update Drupal contributed modules. [#116](https://github.com/CuBoulder/express_mono/issues/116).


__ https://keepachangelog.com/en/1.0.0/
__ https://semver.org/spec/v2.0.0.html