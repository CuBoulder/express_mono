<?php

/**
 * @file
 * Template for Burning Glass include.
 */
?>
<div id="ci"></div>
<script src="https://careerinsight.burning-glass.com/enroll/scripts/cienroll.js"></script>
<script>
    document.body.onload = function() {
        var props = {
            accessCode: '<?php print check_plain($access_code); ?>',
            programCode: '<?php print check_plain($program_code) ?>',
            elementId: 'ci'
        }
        openCI(props);
    }
</script>
