@myTest
Feature: Reviewing Test Content
In order to test Web Express functionality with Behat
As a user with any role at all
I need to know what GitHubActions are looking at


Scenario: Review Page Content
Given I am logged in as a user with the "developer" role
And I am on "admin/settings/news/article-settings"
Then print last response
