# Video rental
## About the project
The .xml file is the result of folowing tutorials during the Data Warehouses and Analitical Processing course. During the project I used following technologies:

* Pentaho Data Integration to design ETL processes
* phpMyAdmin to manage data
* Power Architect to create data warehouse schema
* Application Express to execute SQL commands

### Data
The data warehouse `dwh` is feeded by two data sources: `shop1` and `shop2`. Both of them contain information about the video rental company. Sometimes data between 2 databases is replicated.

### Transformations
Transformation `zaladuj_pracownikow` updates employees table in the data warehouse. Each time it is run it checks the current time and compares it to the latest timestamp. It loads all new employees and search for their addresses in other datatable - to do it it uses sub-transformation `wyszukaj adres`. The last step of the transformation is to update the datatable in the data warehouse.

Transformation `wyszukaj adres` searches for the corresponding address in the database corresponding to the shop. Some of these addresses spread to 2 fields in a such case, the transformation merges them. Then unwantend information are filtered out and the address is returned.

Transformation `zaladuj klientow` loads information about the clients to the data warehouse. Each time it is run it checks the current time and compares it to the latest timestamp. It loads all new clients and checks in which shop the data about client is more up-to-date then it uses the data these data to update information about clients in data warehouse.



