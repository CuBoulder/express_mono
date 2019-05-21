@digital_campaign
Feature: Perform A/B testing using beans.

  @ab_testing
  Scenario: Test A/B blocks.

  Given  I am logged in as a user with the "developer" role
  When I am on "block/a-b-test-block-1"
  Then I should see "a-b-test-block-1"
      And I should see "Text Block A Content AAA"

  When I am on "block/a-b-test-block-2"
  Then I should see "a-b-test-block-2"
      And I should see "Text Block B Content BBB"
