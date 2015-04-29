<?php
/**
 * @file
 * Template file for rendering chartjs charts.
 */

 if ($chart_id): ?>
  <canvas id="chart-<?php echo $chart_id; ?>" width="<?php echo $width; ?>" height="<?php echo $height; ?>"></canvas>
  <script>
    var chart<?php echo $chart_id; ?> = document.getElementById('chart-<?php echo $chart_id; ?>').getContext('2d');
    var chartjs<?php echo $chart_id; ?> = new Chart(chart<?php echo $chart_id; ?>).<?php echo $type; ?>(<?php echo json_encode($data); ?>, <?php echo json_encode($options); ?>);

    <?php if (isset($options['legendTemplate'])): ?>
      var chartjs<?php echo $chart_id; ?>Legend = chartjs<?php echo $chart_id; ?>.generateLegend();
      jQuery('#chart-<?php echo $chart_id; ?>').after(chartjs<?php echo $chart_id; ?>Legend);
    <?php endif; ?>
  </script>
<?php endif; ?>
