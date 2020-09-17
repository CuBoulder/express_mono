@livechat
Feature: LiveChat Integration Feature

Scenario: A site owner can add a LiveChat account.
Given I am logged in as a user with the "site_owner" role
When I go to "admin/settings/livechat/configuration"
Then I should see "Fill in one of the license numbers below."
When I fill in "LiveChatINC.com license number" with "dffdf"
And I press "Save configuration"
Then I should see "The livechat license number must only contain numbers."
When I fill in "LiveChatINC.com license number" with "1234567"
And I press "Save configuration"
Then I should see "The configuration options have been saved."
When I fill in "LiveChatINC.com license number" with "1234567"
And I fill in "AdmitHub.com license number" with "1234567"
And I press "Save configuration"
Then I should see "Only one license number should be entered."
When I fill in "LiveChatINC.com license number" with ""
And I fill in "AdmitHub.com license number" with "1234567"
And I press "Save configuration"
Then I should see "The configuration options have been saved."

# This scenario uses the LiveChat config set up in the last scenario.
@testing_frontpage @javascript
Scenario: The LiveChat code shows up for anonymous users.
Given I go to "node/1"
Then the response should contain "<script type=\"text/javascript\" async=\"\" src=\"http://cdn.livechatinc.com/tracking.js\"></script>"
And the response should contain "#livechat-compact-container { display: none !important;}"

Scenario: An anonymous user should not be able to access the form for adding a class note
When I am on "admin/settings/livechat/configuration"
Then I should see "Access denied"
