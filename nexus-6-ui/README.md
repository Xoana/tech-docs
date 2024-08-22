# Nexus-6 UI

**Topics**
* [Overview](#overview)
    * [Before You Begin](#before-you-begin)
    * [Knowledge Requirements](#knowledge-requirements)
    * [Workspace Requirements](#workspace-requirements)
    * [UI Components](#ui-components)
* [Set Up Your Local Development Environment](#set-up-your-local-development-environment)
* [Additional Topics](#additional-topics)

## Overview

The Nexus-6 UI is built using [Angular](https://angular.io/) and [Node.js](https://nodejs.org/) and is hosted on the following AWS environments using S3 and Cloudfront: 

* Development
* Stage
* Production

### Before You Begin

Ensure you are familiar with the following topics:

* [Knowledge Requirements](#knowledge-requirements)
* [Nexus-6 Development Process](./docs/productx-development-process.md)
* [Nexus-6 Release Process](./docs/productx-release-process.md)

### Knowledge Requirements

* [Angular](https://angular.io/)
* [Nexus-6 Development Process](#productx-development-process)
* [Nexus-6 Release Process](#productx-development-process)
* [Git](https://www.atlassian.com/git/tutorials/learn-git-with-bitbucket-cloud) & [Gitflow](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow)
* [HTML](https://developer.mozilla.org/en-US/docs/Learn/Getting_started_with_the_web/HTML_basics)/[CSS](https://developer.mozilla.org/en-US/docs/Learn/CSS)
* [Javascript](https://www.javascript.com/)/[Typescript](https://www.typescriptlang.org/)
* Nexus-6 API
* [Nexus-6 UI Components](#request-tracker-ui-components)

### Workspace Requirements

* [Python](https://www.python.org/downloads/) (> v3.8.8)
* [Node.js](https://nodejs.org/en/) (v16.13.2)
* [Angular CLI](https://angular.io/guide/setup-local#install-the-angular-cli) (v13.3.10)
* [AWS CLI](https://docs.aws.amazon.com/cli/latest/userguide/install-cliv2.html) (v2.2.0) (Required for the deployment script.)
* Duo SSO (Required for the deployment script; see [Install duo-sso](./docs/install-duo-sso.md).)
* [Git](https://github.com/git-guides/install-git) & [Gitflow](https://www.atlassian.com/git/tutorials/comparing-workflows/gitflow-workflow)
* [SourceTree Git Client](https://www.sourcetreeapp.com/) (Recommended but not required.)

### UI Components

The following table lists the UI components and the page or function to which the code applies.

| Component | Function/Page  |
| :------------- |:-------------|
| activity-log | Activity Log |
| auth | Log In/Authentication |
| create-request | Create Requests |
| header | Header |
| modal | Modal  |
| page-not-found | Page Not Found |
| services | Services used throughout the codebase. |
| shared | Code shared by more than one component. |
| spreadsheet-view | Requests table.<br/>**Note**: The spreadsheet-view also includes subcomponents for services, modals, and custom code used on the requests table.  |
| subscriptions | Subscriptions page. |

## Set Up Your Local Development Environment

To set up your local development environment, complete these steps:

1. Install the necessary applications listed in [Workspace Requirements](#workspace-requirements).
1. Clone this repo as described in [Clone the productx-ui Repository](./docs/git_procedures.md#clone-the-productx-ui-repository).
1. Install and run the UI locally as described in [Install and Run the UI Locally](./docs/install_and_run_the_ui_locally.md).
1. Test the deployment script; see [Build and Deploy the UI](./docs/build_and_deploy_ui.md).

## Additional Topics

* [About Request Forms](./docs/about-request-forms.md)
* [Add a Column to the Create Request Forms](./docs/add_column_to_create_request_form.md)
* [Add a Column to the Requests Table](./docs/add_column_to_requests_table.md)
* [Build and Deploy the UI](./docs/build_and_deploy_ui.md)
* [Nexus-6 Development Process](./docs/productx-development-process.md)
* [Nexus-6 Release Process](./docs/productx-release-process.md)
* [Git Procedures](./docs/git_procedures.md)
* [Install and Run the UI Locally](./docs/install_and_run_the_ui_locally.md)
* [Install duo-sso](./docs/install-duo-sso.md)
* [Nexus-6 Testing](./docs/tracker_testing.md)
* [Update Column Labels and Help Text](./docs/update_labels_and_help_text.md)
