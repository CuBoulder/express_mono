<div id="collection-<?php print $collection['collection_id']; ?>" class="collection-grid collection-filter-effect-<?php print $collection['filter_effect']; ?>">
  <div class="row">
    <div class="col-lg-3 col-md-3 col-sm-12 col-xs-12">
      <div class="collection-grid-filters">
        <form>
          <?php print render($content['filters']); ;?>
          <input type="reset" value="Reset Filters" class="button button-gray-light collection-reset" data-collection="collection-<?php print $collection['collection_id']; ?>"/>
        </form>
      </div>
    </div>
    <div class="col-lg-89 col-md-9 col-sm-12 col-xs-12">
      <div class="results element-invisible"></div>
      <div class="collection-breadcrumbs"></div>
      <div class="collection-grid-items">
        <?php print render($content['items']); ;?>
      </div>
    </div>
  </div>

</div>
