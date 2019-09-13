@digital_campaign
Feature: the Digital Campaign bundle
In order to test the results of a digital campaign
A user with the proper role
Should be able to access and use the Digital Campaign functionality

@role @javascript
Scenario: The Campaign Manager role has been added to role list and invite page
  Given I am logged in as a user with the "developer" role
    And I go to "admin/people/permissions/roles"
  Then I should see "campaign_manager"
    And I go to "admin/people/invite"
      And I wait for the "#edit-addon-rids" element to appear
  Then I should see "This role is tied to the Digital Campaign Bundle"
    And I should see "Campaign Manager"
