<!-- 
The publication first, publications template.

Publication name
Author, Publication Year
Published in
DOI: xx.xxxx/xxxxxxx.xxxxxxxx 
-->

<div class="faculty-publication-listing">
  <h3>
    <?php
      if ($doi) {
        print l($name, 'https://doi.org/' . $doi); 
      } else {
        //If no DOI is given, try looking for the publication on google scholar
        print l($name, 'https://scholar.google.com/scholar?hl=en&q=' . htmlspecialchars($name)); 
      }
    ?>
  </h3>
  <div class="faculty-publication-authors">
    <?php
      $publication_authors = array();
      foreach ($authors as $author) {
        $publication_authors[] = l($author->name, $author->uri);
      }
      echo join(', ', $publication_authors), ' ' . $publicationYear;
    ?>
  </div>
  <div class="faculty-publication-pub-name">
    <?php print $publishedIn->name; ?>
  </div>

  <div class="faculty-publication-doi">
    <?php
      if ($doi) {
        echo 'DOI: ', l($doi, 'https://doi.org/' . $doi);
      }
    ?>
  </div>
</div>
