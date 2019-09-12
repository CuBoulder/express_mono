@digital_campaign
Feature: the Digital Campaign bundle
In order to test the results of a digital campaign
As a user with the proper role
I should be able to access and use the Digital Campaign functionality

Feature: Interaction with the Embed Templates admin screens.


  @embed_templates @current
  Scenario Outline: Access Embed Templates Overview Page.
    Given  I am logged in as a user with the <role> role
    And am on "admin/content/embeds"
    Then I should see <message>

    Examples:
      | role                  | message         |
      | site_owner            | "Add Embeds"    |
      | administrator         | "Add Embeds"    |
      | developer             | "Add Embeds"    |
      | campaign_manager      | "Add Embeds"    |
      | edit_my_content       | "Access Denied" |
      | content_editor        | "Access Denied" |
     # | authenticated_user    | "Access Denied" |
      | site_editor           | "Access Denied" |
      | edit_only             | "Access Denied" |
      | access_manager        | "Access Denied" |
      | configuration_manager | "Access Denied" |
