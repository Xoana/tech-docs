# Troubleshooting

### Customer-specific data does not appear on the Nexus-6 dashboard Data tab or footer

Customer-specific data on the Nexus-6 dashboard is extracted from the `PRODUCTX_AGGREGATION` and `PRODUCTX_CUSTOMER_DETAILS` Snowflake views; these views are limited to only the latest run IDs. Therefore, if the customer-specific data does not appear on the Summary page and the Data tab, the run ID in the URL is most likely not the latest run ID.

If the URL in the Nexus-6 uses an older run ID, it could indicate that the request was run twice within a short amount of time (e.g., seconds or minutes).

This issue can occur when the automation script is run manually at the same time the Control-M job executes. For more information, see [Is it necessary to run requests manually?](frequently-asked-questions.md/#is-it-necessary-to-run-requests-manually)

### The dashboard URL in the Nexus-6 links to a dashboard without any data

This issue can occur if the Sales Level 3 value is manually changed to or from *PS FEDERAL AREA* after the initial run.

For example, if the Sales Level 3 value in the Nexus-6 is changed to *PS FEDERAL AREA* after the initial run, the URL in the Nexus-6 will point to the non-federal template (e.g., `productx`), but the data for that run will appear in the federal template (e.g., `productx_fed`).

**Additional Details:** All views used in the dashboards include a column (`ACCOUNT_TYPE`) that determines whether the federal template should be used for a run; this column extracts data directly from the Sales Level 3 value in the Nexus-6. Additionally, the SQL queries within the templates include a condition that prevents federal data (`ACCOUNT_TYPE = 'FEDERAL'`) from appearing on the non-federal templates. Therefore, changing Sales Level 3 to or from *PS FEDERAL AREA* after the initial run will cause the URL in the Nexus-6 to point to the wrong dashboard.

<hr/>

[Return to README](../../README.md)