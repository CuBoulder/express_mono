@wysiwyg @core
Feature: WYSIWYG Pathologic tests

@javascript @broken
# TO DO: Need to setup Pathologic link in testing module install.
Scenario: Pathologic should change URLs
Given  I am logged in as a user with the "site_owner" role
And I go to "node/add/page"
And I fill in "edit-title" with "PathologicTest"
And I follow "Disable rich-text"
And I fill in "Body" with "<a id=\"pathologic-link\" href=\"http://www.colorado.edu/p1eb825ce549/test\">pathologic</a>"
And I press "Save"
Then The "#pathologic-link" element should have "//127.0.0.1:8888/test" in the "href" attribute
