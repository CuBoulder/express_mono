@digital_campaign
Feature: the Digital Campaign bundle
In order to test the results of a digital campaign
As a user with the proper role
I should be able to access and use the Digital Campaign functionality

@funnelpages
Scenario: The Settings page contains a link to add Campaign Funnel Pages
  Given I am logged in as a user with the "site_owner" role
    And I am on admin/settings
  Then I should see the link "Funnel Pages"

@funnelpages
Scenario Outline:  A user with the proper role can add funnel pages
  Given I am logged in as a user with the <role> role
  When I go to "settings/campaign/funnel-pages"
  Then I should see <message>

  Examples:
    | role             | message         |
    | developer        | "Funnel Pages"  |
    | administrator    | "Funnel Pages"  |
    | site_owner       | "Funnel Pages"  |
    | campaign_manager | "Funnel Pages"  |
    | content_editor   | "Access denied" |
    | edit_my_content  | "Access denied" |
    | site_editor      | "Access denied" |
    | edit_only        | "Access denied" |


@funnelpages
Scenario: An anonymous user cannot add a Funnel Page
  When I am on "settings/campaign/funnel-pages"
  Then I should see "Access denied"

@funnelpages
Scenario: A Funnel Page is properly formatted (no menu bar)
  Given I am logged in as a user with the "site_owner" role
# Create a Basic Page for testing
  When I am on "node/add/page"
    And fill in "edit-title" with "Funnel Page Test"
    And I press "edit-submit"
    Then I should be on "/funnel-page-test"
    And I should see "Funnel Page Test"
    And the response should contain "id=\"navigation\""
# Make this page a funnel page
  Then I go to "admin/settings/campaign/funnel-pages"
  And I fill in ""#edit-cu-funnel-pages" with "funnel-page-test"
  And I press "Save configuration"
  Then I should see "The configuration options have been saved"
  When I go to 'funnel-page-test'
  The response should not contain contain "id=\"navigation\""
