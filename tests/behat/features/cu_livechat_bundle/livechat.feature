@livechat
Feature: LiveChat Integration Feature

Scenario: Values entered for LiveChat and AdmitHub are verified.
Given I am logged in as a user with the "site_owner" role
When I go to "admin/settings/livechat/configuration"
Then I should see "Fill in one of the license numbers below."
# reset the AdmitHub field for testing purposes
And I fill in "AdmitHub.com license number" with ""
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

@testing_frontpage
Scenario: The LiveChat code is placed on page
Given I am logged in as a user with the "site_owner" role
And I go to "admin/settings/livechat/configuration"
And I fill in "LiveChatINC.com license number" with "1234567"
And I fill in "AdmitHub.com license number" with ""
And I press "Save configuration"
And I go to "node/1"
Then the response should contain "#livechat-compact-container"
And the response should not contain "window.adminHubBot"

@testing_frontpage
Scenario: The AdmitHub code is placed on page
Given I am logged in as a user with the "site_owner" role
And I go to "admin/settings/livechat/configuration"
And I fill in "LiveChatINC.com license number" with ""
And I fill in "AdmitHub.com license number" with "1234567"
And I press "Save configuration"
And I go to "node/1"
Then the response should contain "window.admitHubBot"
And the response should not contain "#livechat-compact-container"

Scenario: An anonymous user should not be able to access the form for adding a class note
When I am on "admin/settings/livechat/configuration"
Then I should see "Access denied"
