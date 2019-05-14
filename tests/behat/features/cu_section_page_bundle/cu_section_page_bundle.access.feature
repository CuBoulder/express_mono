@cu_section_page_bundle
Feature: Section Page Node Type

    When I login to a Web Express website
    As an authenticated user with the right permission
    I should be able to create a section page

    Scenario Outline: An authenticated user should be able to access the form for adding a section page
        Given  I am logged in as a user with the <role> role
        When I go to "node/add/section-page"
        Then I should see <message>

        Examples:
            | role            | message               |
            | edit_my_content | "Access Denied"       |
            | edit_only       | "Access Denied"       |
            | content_editor  | "Create Section Page" |
            | site_owner      | "Create Section Page" |
            | administrator   | "Create Section Page" |
            | developer       | "Create Section Page" |

    Scenario: An anonymous user should not be able to access the form for adding a section page
        When I am on "node/add/section-page"
        Then I should see "Access denied"
