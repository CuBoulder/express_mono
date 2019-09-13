@digital_campaign
Feature: Create and edit tracking pixel embeds.

  @tracking_pixels
  Scenario: Create a Facebook tracking pixel.
    Given I am logged in as a user with the "site_owner" role
      And I am on "admin/content/embeds/add/facebook"
      And I fill in "Label" with "Facebook Tracking Pixel"
      And I fill in "Path" with "node/1"
      And I fill in "ID" with "123456"
      And I select "Published" from "Status"
    When I press "Save"
      And I am on "node/1"
    Then the response should contain "https://www.facebook.com/tr?id=123456&ev=PageView&noscript=1"

  @tracking_pixels
  Scenario: Create a DoubleClick tracking pixel.
    Given I am logged in as a user with the "campaign_manager" role
      And I am on "admin/content/embeds/add/doubleclick"
      And I fill in "Label" with "DoubleClick Tracking Pixel"
      And I fill in "Path" with "node/1"
      And I fill in "ID" with "452315"
      And I fill in "Activity" with "activity_one"
      And I fill in "Creation Date" with "creation_date_one"
      And I fill in "Page Location" with "location_one"
      And I fill in "Type" with "type_one"
      And I fill in "Category" with "category_one"
      And I select "Top" from "Position"
      And I select "Published" from "Status"
    When I press "Save"
      And I am on "node/1"
    Then the response should contain "document.write('<iframe src=\"https://452315.fls.doubleclick.net/activityi;src=452315;type=type_one;cat=category_one;dc_lat=;dc_rdid=;tag_for_child_directed_treatment=;ord=' + a + '?\" width=\"1\" height=\"1\" frameborder=\"0\" style=\"display:none\"></iframe>');"


  @tracking_pixels
  Scenario: Create a Twitter tracking pixel.
    Given  I am logged in as a user with the "site_owner" role
      And I am on "admin/content/embeds/add/twitter"
      And I fill in "Label" with "Twitter Tracking Pixel"
      And I fill in "Path" with "node/1"
      And I fill in "ID" with "456789"
      And I fill in "Activity" with "activity_nine"
      And I select "Published" from "Status"
    When I press "Save"
      And I am on "node/1"
    Then the response should contain "twq('init', '456789');"
      And the response should contain "twq('track', 'PageView');"
    And the response should contain "twq('track', 'activity_nine');"


  @tracking_pixels
  Scenario: Create a LinkedIn Insight Tag tracking pixel.
    Given I am logged in as a user with the "campaign_manager" role
      And I am on "admin/content/embeds/add/et_linkedin"
      And I fill in "Label" with "LinkedIn Tracking Pixel"
      And I fill in "Path" with "node/1"
      And I fill in "Account ID" with "9030612"
      And I fill in "Position" with "bottom"
      And I select "Published" from "Status"
    When I press "Save"
      And I am on "node/1"
    Then the response should contain "_linkedin_data_partner_id = \"9030612\";"
      And the response should contain "<img height=\"1\" width=\"1\" style=\"display:none;\" alt=\"\" src=\"https://dc.ads.linkedin.com/collect/?pid=9030612&fmt=gif\"/>"

