@layout
Feature: CU Layout Creation
  Users should be able to create and edit layouts.
  When I go to the Edit Layout page
  As a user with the proper role
  I should be able to affect page layout by adding blocks to regions

# NOTE: Running multiple tests of this scenario creates many pages all named
# 'My Layout Page', each with a unique URL. To solve the problem of trying to
# target these pages for block addition/deletion over multiple test runs,
# all tests are run within the same scenario.

@javascript
Scenario: A block can be added to and deleted from a region on the Edit Layout page
# Create basic page for testing this functionality
  Given I am logged in as a user with the "site_owner" role
    And I am on "node/add/page"
    And fill in "edit-title" with "My Layout Page"
    And I follow "Disable rich-text"
    And fill in "Body" with "Web Express sites can create complex and dynamic layouts of content"
    And I uncheck "edit-menu-enabled"
  When I press "edit-submit"
  Then I should see "Web Express sites can create complex and dynamic layouts of content"
# Add a block to a region
  When I follow "Edit Layout"
    And I wait for the ".field-name-field-sidebar-first" element to appear
    And I select "block" from "field_sidebar_first[und][actions][bundle]"
    And I wait for the ".ief-form" element to appear
    And I fill in "Text Block Label" with "Left Sidebar Block Label"
    And I follow "Disable rich-text"
    And I fill in "Body" with "Left Sidebar Block Text"
    And I press "Create block"
    And I press "Update layout"
  Then I should see "Left Sidebar Block Text"
# Remove a block from a region
  When I follow "Edit Layout"
    And I wait for the ".field-name-field-sidebar-first" element to appear
    And I should see "Left Sidebar Block Label"
    And I press "Remove"
    And I wait for the ".ief-form" element to appear
    And I check "edit-field-sidebar-first-und-entities-0-form-delete"
    And I press "Remove"
    And I press "Update layout"
  Then I should not see "Left Sidebar Block Text"

@broken
## @TODO Get autocomplete suggestion to work
#Scenario: You should be able to add an existing block to the page layout
#When I click "Edit Layout"
#And I click the "#edit-field-sidebar-first-und-actions-ief-add-existing" element
#And I wait for AJAX
#And I fill in "field_sidebar_first[und][form][entity_id]" with "abo"
#And I wait 5 seconds
#And I select autosuggestion option "above content block"
