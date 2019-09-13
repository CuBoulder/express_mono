@digital_campaign
Feature: Perform A/B testing using beans.

  @ab_testing @javascript
  Scenario: Create An A/B test.
    Given  I am logged in as a user with the "developer" role
    # Turning the auto-complete field into a select list doesn't work like on my local...
    When I go to "admin/structure/field-collections/field-block-option/fields/field_block/widget-type"
      And I select "Select list" from "Widget type"
      And I press "Continue"
    When I am on "block/add/a-b-block"
      And I fill in "Label" with "A/B Block"
      And I select "Text Block A (Text Block A)" from "field_block_option[und][0][field_block][und]"
      And I fill in "edit-field-block-option-und-0-field-percentage-und-0-value" with "100"
      And I press "Add another item"
      And I wait for the ".ajax-new-content" element to appear
      And I select "Text Block B (Text Block B)" from "field_block_option[und][1][field_block][und]"
      And I fill in "edit-field-block-option-und-1-field-percentage-und-0-value" with "0"
    When I press "Save"
    Then I should see "A/B Block"
      And I should see "Text Block A Content AAA"
    When I follow "Edit Block"
      And I fill in "edit-field-block-option-und-0-field-percentage-und-0-value" with "0"
      And I fill in "edit-field-block-option-und-1-field-percentage-und-0-value" with "100"
    When I press "Save"
    Then I should see "A/B Block"
      And I should see "Text Block B Content BBB"
