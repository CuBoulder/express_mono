 <!-- The author first, publications template.

 Author, Publication Year
 Publication name
 Published In
 DOI: xx.xxxx/xxxxxxx.xxxxxxxx 
 -->
 
<div class="faculty-publication-listing">
  <h3>
    <?php
      $publication_authors = array();
      foreach ($authors as $author) {
        $publication_authors[] = l($author->name, $author->uri);
      }
      print join(', ', $publication_authors);
      print ' ' . $publicationYear;
    ?>
  </h3>

  <div class="faculty-publication-name">
    <?php
      if ($doi) {
        print l($name, 'https://doi.org/' . $doi); 
      }
      else {
        print l($name, 'https://scholar.google.com/scholar?hl=en&as_sdt=0%2C6&q=' . htmlspecialchars($name)); 
      }
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
