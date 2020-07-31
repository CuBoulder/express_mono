@wysiwyg @core
Feature: WYSIWYG Pathologic tests

@javascript
# TO DO: Need to setup Pathologic link in testing module install.
Scenario: Pathologic should change URLs
  Given I am logged in as a user with the "developer" role
  And I am on "admin/config/content/formats/wysiwyg"
  And I fill in "filters[pathologic][settings][local_paths]" with "http://www.colorado.edu/p1eb825ce549"
  And I press "Save"
  And I go to "node/add/page"
  And I fill in "edit-title" with "PathologicTest"
  And I follow "Disable rich-text"
  And I fill in "Body" with "<a href=\"http://www.colorado.edu/p1eb825ce549/testpage\" name=\"myPathoName\" id=\"myPathoName\" >Change This Link</a>"
  When I press "Save"
  # FOR LOCAL TESTING, UNCOMMENT NEXT LINE AND CHANGE DOMAIN TO YOUR LOCAL SERVER
  # And the "#myPathoName" element should have "http://mylocal.lndo.site/mytestpage" in the "href" attribute
  # FOR TRAVIS TESTING, UNCOMMENT NEXT LINE
  Then the "#myPathoName" element should have "http://127.0.0.1:8031/testpage" in the "href" attribute
