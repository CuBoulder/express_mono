@digital_campaign
Feature: the Digital Campaign bundle
In order to test the results of a digital campaign
As a user with the proper role
I should be able to access and use the Digital Campaign functionality

Scenario: The Campaign Manager role has been added to Roles
  Given I am logged in as a user with the "developer" role
    And I go to "admin/people/permissions/roles"
  Then I should see "campaign_manager"
  When I go to "admin/people/invite"
  Then I should see "Campaign Manager"
