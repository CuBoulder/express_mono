@cu_publications_bundle
Feature: Issue Node Type

        When I login to a Web Express website
    As an authenticated user with the right permission
    I should be able to create an Issue

    Scenario Outline: An authenticated user should be able to access the form for adding an issue
        Given  I am logged in as a user with the <role> role
        When I go to "node/add/issue"
        Then I should see <message>

        Examples:
            | role            | message         |
            | edit_my_content | "Access Denied" |
            | edit_only       | "Access Denied" |
            | content_editor  | "Create Issue"  |
            | site_owner      | "Create Issue"  |
            | administrator   | "Create Issue"  |
            | developer       | "Create Issue"  |

    Scenario: An anonymous user should not be able to access the form for adding an issue
        When I am on "node/add/issue"
        Then I should see "Access denied"