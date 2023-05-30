/*
Write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.
  - Your query should output a table with a single column for the name of each person.
*/

SELECT DISTINCT name
FROM directors
JOIN ratings ON movies.id = ratings.movie_id
JOIN movies ON directors.movie_id = movies.id
JOIN people ON directors.movie_id = people.id
WHERE ratings.rating >= 9.0 ;
