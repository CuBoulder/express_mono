<div class="padding-bottom margin-bottom">
  <h3 class="h5">
    <?php
      if ($doi) {
        print l($name, 'https://dx.doi.org/' . $doi, array('html' => TRUE));
      }
      else {
        print $name;
      }
    ?>
  </h3>
  <div id="cu-authors">
    <strong>CU Boulder Authors:</strong>
    <?php
      $names = array();
      foreach ($authors as $author) {
        $names[] = l($author['name'], $author['uri']);
      }
      print implode('; ', $names);
    ?>
  </div>
  <div style="display: flex">
    <strong>All Authors: </strong>
    <?php if (strlen($citedAuthors) < 100): ?>
      <?php print $citedAuthors; ?>

    <?php else: ?>
      <?php $allAuthorArray = explode("; ", $citedAuthors); ?>
      <details style="margin-left: 1rem" id="all-authors">
        <summary>
          <span id=all-authors-truncated><?php print substr($citedAuthors, 0, 100) . "..."; ?></span>
        </summary>

        <ul id="all-authors-list">

          <?php foreach($allAuthorArray as $author): ?>
            <li><?php print $author; ?></li>
          <?php endforeach; ?>

        </ul>
      </details>
    <?php endif; ?>
  </div>
  <?php if (!empty($publishedIn)): ?>
    <strong>Published in:</strong> <?php print l($publishedIn['name'], $publishedIn['uri']); ?><br />
  <?php endif; ?>
  <strong>Publication Date:</strong> <?php print $publicationDate; ?><br />
  <strong>Type:</strong> <?php print $mostSpecificType; ?>
</div>
<!-- <script>
  const allAuthors = document.querySelector('.all-authors');
  const allAuthorsTruncated = document.querySelector('.all-authors-truncated')
  const allAuthorsList = document.querySelector('.all-authors-list')
  allAuthors.addEventListener("toggle", (event) => {
    allAuthorsTruncated.toggleAttribute("hidden")
    allAuthorsList.toggleAttribute("hidden")
  })
</script> -->
