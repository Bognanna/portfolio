# Video rental
## About the project
The .xml file is the result of folowing tutorials during the Data Warehouses and Analitical Processing course. During the project I used following technologies:

* Pentaho Data Integration to design ETL processes
* phpMyAdmin and phpPGAdmin to manage data
* Power Architect to create data warehouse schema
* Application Express and SQL*Plus to execute SQL commands

### Data
The data warehouse `dwh` is feeded by two data sources: `shop1` and `shop2`. Both of them contain information about the video rental company. Sometimes data between 2 databases is replicated (not always fully). Another data source is .csv file `US` which contains information about cities and villages in USA. There is also .xml file `filmy` that contains information about movies, that information is from a website. Also information about actors comes from a website, however access to them is realised by REST client.

### Transformations
Transformation `zaladuj_pracownikow` updates employees table in the data warehouse. Each time it is run it checks the current time and compares it to the latest timestamp. It loads all new employees and search for their addresses in other datatable - to do it it uses sub-transformation `wyszukaj adres`. The last step of the transformation is to update the datatable in the data warehouse.

Transformation `wyszukaj adres` searches for the corresponding address in the database corresponding to the shop. Some of these addresses spread to 2 fields in a such case, the transformation merges them. Then unwantend information are filtered out and the address is returned.

Transformation `zaladuj klientow` loads information about clients to the data warehouse. Each time it is run it checks the current time and compares it to the latest timestamp. It loads all new clients and checks in which shop the data about client is more up-to-date then it uses the data these data to update information about clients in data warehouse.

Transformation `zaladuj filmy` loads information about movies to the data warehouse. Each time it is run it checks the current time and compares it to the latest timestamp. It selects all new movies and eliminates duplicates.

Transformation `generowanie wymiaru daty` generates rows with subseqent dates to create a DATE dimension in the data warehouse.

Transformation `zaladuj fakty` loads information about rentals to the data warehouse. Each time it is run it checks the current time and compares it to the latest timestamp. It searches for the movie id based on its title and publishing year and fills information about return day if movie wasn't returned.

Transformation `porownanie stany kraje` adds markers to data that changed in datasource `US`. Changes are spotted using Snapshot-Based CDC. All not changed values and those which were deleted are filtered out. Rest of data is used to update `geonames_org` table.

Transformation `popraw zmienione stany kraje` updates clients datatable with marked as updated data about states and regions from `geonames_org` table.

Transformation `uzupelnij stany kraje` fills empty fields for clients who doesn't have state and region provieded in datatable.

Transformation `dodaj filmy` loads info about movies from a website, validates it and modifies column with extras, denormalising it. Finally it updates the movie datatable.

Transformation `dodaj aktorow` loads info about actors using rest client and updates the actors datatable and actors_movies datatable.

### Jobs
Job `odswiez dwh` runs all transformations that fills the data warehouse in proper order.

Job `ladowanie stanow okregow` updates information about region and states in clients dimension and resets markers in `geonames_org` datatable.

Job `ladowanie filmow` runs transformations that updates movies, actors and movie_actors datatables.


