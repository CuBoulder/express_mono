@status_checks
Feature: Site Install Status Checks
#  When the site is installed, there should be no errors.
#
#@run_first @javascript
#  Scenario: On install the status report page shouldn't show any errors.
#    Given I am logged in as a user with the "developer" role
#    When I go to "admin/reports/status"
#    Then the response should not contain "<tr class=\"error\">"
#      And the response should not contain "<div class=\"messages error\">"

# @testrun NORMAL LOGIN; HIDE FOR NOW
#  Scenario: SauceConnect can run Selenium tests
#  Given I am logged in as a user with the "developer" role
#  And I am on "node/1"
#  When I follow "Edit"
#  Then I should see "This document is now locked against simultaneous editing."

  @testrun
  Scenario: Making a connection
  Given I am on "user"
  And I fill in "edit-name" with "developer"
  And I fill in "edit-pass" with "developer"
  When I press "Log in"
  Then I should be on "admin/dashboard/user"

  @testrun @javascript
   Scenario: SauceConnect can run Selenium tests
   Given I am on "user"
   And I fill in "edit-name" with "developer"
   And I fill in "edit-pass" with "developer"
   When I press "Log in"
   Then I should be on "admin/dashboard/user"
