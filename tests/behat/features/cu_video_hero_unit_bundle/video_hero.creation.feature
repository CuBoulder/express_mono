@video_hero_unit
Feature: Video Hero Unit Block

    When I login to a Web Express website
    As an authenticated user with the right permission
    I should be able to create a Video Hero Unit block

    Scenario Outline: An authenticated user should be able to access the form for a Video Hero Unit block
        Given  I am logged in as a user with the <role> role
        When I go to "block/add/video-hero-unit"
        Then I should see <message>

        Examples:
            | role            | message                        |
            | edit_my_content | "Access Denied"                |
            | edit_only       | "Access Denied"                |
            | content_editor  | "Create Video Hero Unit block" |
            | site_owner      | "Create Video Hero Unit block" |
            | administrator   | "Create Video Hero Unit block" |
            | developer       | "Create Video Hero Unit block" |

    Scenario: An anonymous user should not be able to access the form for adding a Video Hero Unit block
        When I am on "block/add/video-hero-unit"
        Then I should see "Access denied"