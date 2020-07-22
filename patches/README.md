# Patches

## Patch: jquery.ui.dialog.patch.js
Module: views
Change Made: jQuery bug fix; bug makes it impossible to scroll page when modal dialog is active. This JavaScript patch overwrites the $.ui.dialog.overlay.events object

Patch: 1280930-description-50.patch
Module: simplesamlphp_auth
File Patched: simplesamlphp_auth.admin.inc
Change Made: Add description to Simple SAML Auth Settings "Upon federated login, check if a local, pre-existing Drupal user is present with a username equal to the SAML authname ..."

Patch: express-skip-slo-redirect.patch
Module: simplesamlphp_auth
File Patched: simplesamlphp_auth.module
Change Made: Add Express Custom Conditional "If simplesamlphp_auth_slo_redirect is set, then destroy the local session AND redirect to feadauth single logout page. Otherwise, destroy local session only and don't redirect "

Patch: simplesamlphp_auth-2476707-12.patch
Module: simplesamlphp_auth
File Patched: simplesamlphp_auth.pages.inc
Change Made: Require user to authenticated; then send them along

Patch file: pantheon-sso-dashboard-redirect.patch
Module: simplesamlphp_auth
File Patched: simplesamlphp_auth.pages.inc
Change Made: Redirect to admin/dashboard after logging in (this patches the patch above 'simplesamlphp_auth-2476707-12e')

Patch: missing-contextual-link.patch
Module: bean
File Patched: bean.module
Change Made: add contextual link to bean block

Patch: bean-integration-2127731-10.patch
Module: linkchecker
File Patched: linkchecker/module/linkchecker_bean/ .info and .install and .module
Change Made: create linkchecker_bean module as submodule of linkchecker


