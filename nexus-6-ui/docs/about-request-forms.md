# About Request Forms

## Overview

The request forms, including the Create Request landing page, are built as a single page using Nexus-6 UI Angular components. The HTML code for the landing page and all request forms is located in the create-request.component.html file. Form fields on the request forms are displayed or hidden using Angular directives (e.g. ```*ngIf```).

## Knowledge Requirements

In addition to the items listed in [Knowledge Requirements](../README.md#knowledge-requirements), you should be familiar with the following items to make changes to this code:

* Angular [Built-in structural directives](https://angular.io/guide/built-in-directives#built-in-structural-directives) (specifically, ```ngIf``` and ```ngFor```)
* Nexus-6 Angular Components
* [Displaying values with interpolation](https://angular.io/guide/interpolation)

## HTML File Code Structure

The html file includes two main sections: the Create Request landing page and the request forms.

* The Create Request landing page begins directly after the ```<h2>``` element in which the ```pageTitle$``` observable appears and is displayed when the user clicks the Create Request button located above the requests table.
* The request forms fields follow the landing page and are displayed or hidden using mainly the ```ngIf``` Angular directive based on which button the user clicks on the landing page.

<hr/>

[Return to README](../README.md)