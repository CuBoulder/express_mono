<!doctype html>
<!--[if lt IE 7]>      <html class="no-js lt-ie9 lt-ie8 lt-ie7" lang=""> <![endif]-->
<!--[if IE 7]>         <html class="no-js lt-ie9 lt-ie8" lang=""> <![endif]-->
<!--[if IE 8]>         <html class="no-js lt-ie9" lang=""> <![endif]-->
<!--[if gt IE 8]><!--> <html class="no-js" lang=""> <!--<![endif]-->
    <head>
        <meta charset="utf-8">
        <meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">
        <title>Campus Map | University of Colorado Boulder</title>
        <meta name="description" content="Campus map of the University of Colorado Boulder">
        <meta name="viewport" content="width=device-width, initial-scale=1">
        <?php
          global $base_url;
          $path = $base_url . '/' . drupal_get_path('module', 'cu_campus_map_bundle');

        ?>
        <script src="<?php print $path; ?>/js/jquery.min.js"></script>
        <style>
          html, body {
            height:100%;
            margin:0;
            padding:0;
          }
          .element-invisible { border: 0; height: 1px; overflow: hidden; padding: 0; position: absolute !important; width: 1px; white-space: nowrap; }
        </style>
    </head>
    <body>
        <div class="element-invisible">
          CU Boulder is committed to making information available via assistive technologies. The campus map has known issues with certain assistive technologies that we are working with the supplier to resolve.
        </div>
        <iframe id="map_frame" width="100%" height="100%" src="https://map.concept3d.com/?id=336" frameborder="0" scrolling="no" border="0" allow="geolocation"></iframe>

      <script type="text/javascript">
      jQuery( document ).ready(function() {
      function getUrlParameter(sParam)
      {
          var sPageURL = window.location.search.substring(1);
          var sURLVariables = sPageURL.split('&');
          // console.log(sURLVariables);
          for (var i = 0; i < sURLVariables.length; i++)
          {
              var sParameterName = sURLVariables[i].split('=');
              if (sParameterName[0] == sParam)
              {
                  return sParameterName[1];
              }
          }
      }
      if (window.location.search) {
        // var id = getUrlParameter('id');
        var map_frame = document.getElementById('map_frame');
        var mrkIid = getUrlParameter('mrkIid');
        var build_parameter = "?&mrkIid="+mrkIid;
        // console.log(mrkIid);
        if(mrkIid === undefined){
           //do nothing
        }
        else{

        }
        //append url parameter to iframe
         var src = 'https://map.concept3d.com/';
        src += window.location.search + window.location.hash;
        $('iframe#map_frame').attr( "src", src );
      }
      });
      </script>
    </body>
</html>
