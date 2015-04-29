# Chart.js for Drupal

This module brings the [Chart.js](http://www.chartjs.org/) JavaScript chart library to Drupal, and enables dependant modules to create charts in PHP or JavaScript.

## Installation
* Download the latest release of this module, and enable it within Drupal (`drush en -y chartjs`).
* Download the [Chart.js](https://github.com/nnnick/Chart.js) library into a `Chart.js` folder in `sites/all/libraries`.

## Configuration
Chart.js charts can be configured on a chart-by-chart basis, but if you'd like to provide [global (and overrideable) settings](http://www.chartjs.org/docs/#line-chart-chart-options) for your all of your site charts, this can be done by visiting Chart.js administration page: `admin/config/chartjs`. here you can globally configure legends, animations, scale, display, and tooltips.

## Use
This module can be used to define and create charts on both the server side (PHP) and the client side (JavaScript).

### Creating Charts On the Server
The chartjs module contains a function that returns the html/js necessary to render a chart based on the parameters passed in. Here's an example implementation:

```
/**
 * This function uses "chartjs_get_chart" to return html for a chart.
 */
function mymodule_return_chart($data) {
  // Define an array of objects that will be turned
  // into JSON and passed into Chart.js.
  // This data format will change based on chart type.
  // See http://www.chartjs.org/docs
  // For now we'll just create a Doughnut chart.
  $data = array();
  $data[] = (object)array(
    'value' => 10,
    'label' => t('Pizza'),
    'color' => '#000000',
  );
  $data[] = (object)array(
    'value' => 5,
    'label' => t('Beer'),
    'color' => '#EEEEEE',
  );

  // Now we create an array of options that determine
  // how this chart is rendered.
  // See http://www.chartjs.org/docs for global
  // and chart-specific options.
  $options['legendTemplate'] = variable_get('mymodule_chartLegendTemplate');

  /**
   * Return the rendered chart.
   * Here is some parameter documentation:
   *
   * @param string $type
   *   Type of chart that should be returned.
   * @param array $data
   *   Data that should be charted.
   * @param string $id
   *   Unique ID of chart.
   * @param array $options
   *   Options that override global defaults.
   * @param int $width
   *   Width of chart.
   * @param int $height
   *   Height of chart.
   */
  return chartjs_get_chart('doughnut', $data, 'MyChartId', $options, 200, 200);
 }

 /**
  * Implements hook_form().
  * Now let's add our chart to a form.
  */
function mymodule_form($form, &$form_state) {
  $form['votes_chart'] = array(
    '#markup' => mymodule_return_chart(),
  );

  return $form;
}
```

### Creating charts On the Client
Creating client-side charts is easy. Simply follow the [documentation available on the Chart.js project site.](http://www.chartjs.org/docs/).
