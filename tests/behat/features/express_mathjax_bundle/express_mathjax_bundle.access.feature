@express_mathjax_bundle
Feature: Access Mathjax Configuration

    Scenario: An developer user should be able to access the form for configuring mathjax
        Given  I am logged in as a user with the developer role
        When I am on "admin/config/content/mathjax"
        Then I should see "MathJax"
