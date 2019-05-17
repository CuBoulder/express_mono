<div class="collection-filter-links-wrapper collection-filter-links-single">
  <?php if ($label): ?>
    <h3 class="collection-filter-label"><span><?php print $label; ?></span></h3>
  <?php else: ?>
    <h3 class="collection-filter-label element-invisible">Filter</h3>
  <?php endif; ?>
  <div class="collection-filter-links">
    <button data-collection="collection-<?php print $collection_id; ?>" class="collection-filter-clear">All</button>
    <?php foreach ($collection_filter_terms as $term): ?>
      <button data-collection="collection-<?php print $collection_id; ?>" data-collection-category="<?php print _express_collections_bundle_clean_string($term->name); ?>" data-collection-category-hash="#<?php print _express_collections_bundle_clean_string($term->name); ?>"><?php print $term->name; ?></button>
    <?php endforeach; ?>
  </div>
</div>
