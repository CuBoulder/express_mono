<div class="collection-filter-links-wrapper collection-filter-links-multiple  <?php if (isset($image)) { print 'collection-filter-links-bg'; } ?>" <?php
  if (isset($image)) {
    print "style=background-image:url('$image');";
  }
?>>
  <div class="collection-filter-links-inner">
    <h3 class="collection-filter-label" aria-controls="collection-<?php print $collection_id; ?>-filter-links">
      <a href="#collection-<?php print $collection_id; ?>-filter-links" aria-expanded="false">
        <span><?php print $label; ?></span>
    </a>
    </h3>
    <div class="collection-filter-links" id="collection-<?php print $collection_id; ?>-filter-links">
      <div class="collection-links-buttons">
        <button data-collection="collection-<?php print $collection_id; ?>" class="collection-filter-clear">All</button>
        <?php foreach ($collection_filter_terms as $term): ?>
          <button data-collection="collection-<?php print $collection_id; ?>" data-collection-category="<?php print _express_collections_bundle_clean_string($term->name); ?>" data-collection-category-hash="#<?php print _express_collections_bundle_clean_string($term->name); ?>"><?php print $term->name; ?></button>
        <?php endforeach; ?>
      </div>
    </div>
  </div>
</div>
