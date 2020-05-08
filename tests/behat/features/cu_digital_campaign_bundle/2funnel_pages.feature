@digital_campaign
Feature: the Digital Campaign bundle
In order to test the results of a digital campaign
A user with the proper role
Should be able to access and create funnel pages

@funnelpages
Scenario: The Settings page contains a link to add Campaign Funnel Pages
  Given I am logged in as a user with the "site_owner" role
    And I am on "admin/settings"
  Then I should see the link "Funnel Pages"

@funnelpages
Scenario Outline:  A user with the proper role can add funnel pages
  Given I am logged in as a user with the <role> role
  When I go to "admin/settings/campaign/funnel-pages"
  Then I should see <message>

  Examples:
    | role             | message         |
    | developer        | "Funnel Pages"  |
    | administrator    | "Funnel Pages"  |
    | site_owner       | "Funnel Pages"  |
  #  | campaign_manager | "Funnel Pages"  | ADD ON ROLE
    | edit_my_content  | "Access denied" |
    | site_editor      | "Access denied" |
    | edit_only        | "Access denied" |


@funnelpages
Scenario: An anonymous user cannot add a Funnel Page
  When I am on "admin/settings/campaign/funnel-pages"
  Then I should see "Access denied"

@funnelpages @javascript
Scenario: A Funnel Page can be added
  Given I am logged in as a user with the "site_owner" role
# Create a two Basic Pages for testing
    And I go to "node/add/page"
    And fill in "edit-title" with "PageOne"
    And the checkbox "edit-menu-enabled" is checked
    And I press "edit-submit"
  Then I should see "PageOne"
    And I go to "node/add/page"
    And fill in "edit-title" with "PageTwo"
    And the checkbox "edit-menu-enabled" is checked
    And I press "edit-submit"
  Then I should be on "/pagetwo"
    And I should see "PageTwo"
  # The main menu navigation is visible
    And I should see "PageOne"
# Make this page a funnel page
  Then I go to "admin/settings/campaign/funnel-pages"
    And I fill in "cu_funnel_pages" with "pagetwo"
    And I press "Save configuration"
  Then I should see "The configuration options have been saved"
  When I go to "/pageone"
    And I should see "PageOne"
  Then I should see "PageTwo"
  When I go to "/pagetwo"
    Then I should see "PageTwo"
  # The main menu navigation is not visible
    But I should not see "PageOne"
