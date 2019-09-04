@layout
Feature: CU Layout Creation
Users should be able to create and edit layouts.
When I go to the Edit Layout page
As a user with the proper role
I should be able to affect page layout by adding blocks to regions

# NOTE: RUNNING MULTIPLE TESTS OF THIS SCENARIO CREATES MANY PAGES ALL NAMED
# 'MY LAYOUT PAGE' EACH WITH A SEPARATE URL. TO SOLVE THE PROBLEM OF TRYING TO
# TARGET THESE PAGES, ALL THE TESTS ARE RUN WITHIN THE SAME SCENARIO

@javascript
Scenario: A block can be added to and deleted from a region on the Edit Layout page
# CREATE BASIC PAGE FOR TESTING THIS FUNCTIONALITY
Given I am logged in as a user with the "site_owner" role
And I am on "node/add/page"
And fill in "edit-title" with "My Layout Page"
And I follow "Disable rich-text"
And fill in "Body" with "Web Express sites can create complex and dynamic layouts of content"
And I uncheck "edit-menu-enabled"
When I press "edit-submit"
Then I should see "Web Express sites can create complex and dynamic layouts of content"
# ADD A BLOCK TO A REGION
Then I follow "Edit Layout"
And I wait for the ".field-name-field-sidebar-first" element to appear
And I select "block" from "field_sidebar_first[und][actions][bundle]"
And I wait for the ".ief-form" element to appear
And I fill in "Text Block Label" with "Left Sidebar Block Label"
And I follow "Disable rich-text"
And I fill in "Body" with "Left Sidebar Block Text"
And I press "Create block"
And I press "Update layout"
Then I should see "Left Sidebar Block Text"
## REMOVE A BLOCK FROM A REGION
Then I follow "Edit Layout"
And I wait for the ".field-name-field-sidebar-first" element to appear
Then I should see "Left Sidebar Block Label"
And I press "Remove"
#And I wait for the "#edit-field-header-und-entities-0-form-actions-ief-remove-confirm" element to appear
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
