<?php
/**
 * @file
 * Contains administrative tools for chartjs.
 */

/**
 * Admin settings form for chartjs.
 *
 * @return array
 *   Render array for chartjs system settings form.
 */
function chartjs_admin() {
  $form = array();

  $form['chartjs_legend'] = array(
    '#type' => 'fieldset',
    '#title' => t('Legend'),
  );
  $form['chartjs_legend']['chartjs_hasLegend'] = array(
    '#type' => 'radios',
    '#title' => t('Legend'),
    '#options' => array(
      TRUE => t('On'),
      FALSE => t('Off'),
    ),
    '#default_value' => variable_get('chartjs_hasLegend', TRUE),
  );
  $form['chartjs_legend']['chartjs_legendTemplate'] = array(
    '#type' => 'textarea',
    '#title' => t('Legend Template'),
    '#default_value' => variable_get('chartjs_legendTemplate', '<ul class="<%=name.toLowerCase()%>-legend"><% for (var i=0; i<segments.length; i++){%><li><span style="background-color:<%=segments[i].fillColor%>"></span><%if(segments[i].label){%><%=segments[i].label%><%}%></li><%}%></ul>'),
  );

  $form['chartjs_animations'] = array(
    '#type' => 'fieldset',
    '#title' => t('Animations'),
  );
  $form['chartjs_animations']['chartjs_animation'] = array(
    '#type' => 'radios',
    '#title' => t('Animation'),
    '#options' => array(
      'true' => t('On'),
      'false' => t('Off'),
    ),
    '#default_value' => variable_get('chartjs_animation', 'true'),
  );
  $form['chartjs_animations']['chartjs_animationSteps'] = array(
    '#type' => 'textfield',
    '#title' => t('Animation Steps'),
    '#default_value' => variable_get('chartjs_animationSteps', '60'),
  );
  $form['chartjs_animations']['chartjs_animationEasing'] = array(
    '#type' => 'textfield',
    '#title' => t('Animation Easing'),
    '#default_value' => variable_get('chartjs_animationEasing', 'easeOutQuart'),
  );

  $form['chartjs_scale'] = array(
    '#type' => 'fieldset',
    '#title' => t('Scale'),
  );
  $form['chartjs_scale']['chartjs_showScale'] = array(
    '#type' => 'radios',
    '#title' => t('Show Scale'),
    '#options' => array(
      'true' => t('On'),
      'false' => t('Off'),
    ),
    '#default_value' => variable_get('chartjs_showScale', 'true'),
  );
  $form['chartjs_scale']['chartjs_scaleOverride'] = array(
    '#type' => 'radios',
    '#title' => t('Scale Override'),
    '#options' => array(
      'true' => t('On'),
      'false' => t('Off'),
    ),
    '#default_value' => variable_get('chartjs_scaleOverride', 'true'),
  );
  $form['chartjs_scale']['chartjs_scaleSteps'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale Steps'),
    '#default_value' => variable_get('chartjs_scaleSteps', 'null'),
  );
  $form['chartjs_scale']['chartjs_scaleStepWidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale Width'),
    '#default_value' => variable_get('chartjs_scaleStepWidth', 'null'),
  );
  $form['chartjs_scale']['chartjs_scaleStartValue'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale Start Value'),
    '#default_value' => variable_get('chartjs_scaleStartValue', 'null'),
  );
  $form['chartjs_scale']['chartjs_scaleLineColor'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale Line Color'),
    '#default_value' => variable_get('chartjs_scaleLineColor', 'rgba(0,0,0,.1)'),
  );
  $form['chartjs_scale']['chartjs_scaleLineWidth'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale Line Width'),
    '#default_value' => variable_get('chartjs_scaleLineWidth', '1'),
  );
  $form['chartjs_scale']['chartjs_scaleShowLabels'] = array(
    '#type' => 'radios',
    '#title' => t('Scale Show Labels'),
    '#options' => array(
      'true' => t('On'),
      'false' => t('Off'),
    ),
    '#default_value' => variable_get('chartjs_scaleShowLabels', 'true'),
  );
  $form['chartjs_scale']['chartjs_scaleLabel'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale Label'),
    '#default_value' => variable_get('chartjs_scaleLabel', '<%=value%>'),
  );
  $form['chartjs_scale']['chartjs_scaleIntegersOnly'] = array(
    '#type' => 'radios',
    '#title' => t('Scale Integers Only'),
    '#options' => array(
      'true' => t('On'),
      'false' => t('Off'),
    ),
    '#default_value' => variable_get('chartjs_scaleIntegersOnly', 'true'),
  );
  $form['chartjs_scale']['chartjs_scaleBeginAtZero'] = array(
    '#type' => 'radios',
    '#title' => t('Scale Begin At Zero'),
    '#options' => array(
      'true' => t('On'),
      'false' => t('Off'),
    ),
    '#default_value' => variable_get('chartjs_scaleBeginAtZero', 'true'),
  );
  $form['chartjs_scale']['chartjs_scaleFontFamily'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale Font Family'),
    '#default_value' => variable_get('chartjs_scaleFontFamily', "'Helvetica Neue', 'Helvetica', 'Arial', sans-serif"),
  );
  $form['chartjs_scale']['chartjs_scaleFontSize'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale Font Size'),
    '#default_value' => variable_get('chartjs_scaleFontSize', '12'),
  );
  $form['chartjs_scale']['chartjs_scaleFontStyle'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale Font Style'),
    '#default_value' => variable_get('chartjs_scaleFontStyle', 'normal'),
  );
  $form['chartjs_scale']['chartjs_scaleFontColor'] = array(
    '#type' => 'textfield',
    '#title' => t('Scale Font Color'),
    '#default_value' => variable_get('chartjs_scaleFontColor', '#fff'),
  );

  $form['chartjs_display'] = array(
    '#type' => 'fieldset',
    '#title' => t('Display Settings'),
  );
  $form['chartjs_display']['chartjs_responsive'] = array(
    '#type' => 'radios',
    '#title' => t('Responsive'),
    '#options' => array(
      'true' => t('On'),
      'false' => t('Off'),
    ),
    '#default_value' => variable_get('chartjs_responsive', 'true'),
  );
  $form['chartjs_display']['chartjs_maintainAspectRatio'] = array(
    '#type' => 'radios',
    '#title' => t('Mantain Aspect Ration'),
    '#options' => array(
      'true' => t('On'),
      'false' => t('Off'),
    ),
    '#default_value' => variable_get('chartjs_maintainAspectRatio', 'true'),
  );

  $form['chartjs_tooltips'] = array(
    '#type' => 'fieldset',
    '#title' => t('Tooltips'),
  );
  $form['chartjs_tooltips']['chartjs_showTooltips'] = array(
    '#type' => 'radios',
    '#title' => t('Show Tool Tips'),
    '#options' => array(
      'true' => t('On'),
      'false' => t('Off'),
    ),
    '#default_value' => variable_get('chartjs_showTooltips', 'true'),
  );
  $form['chartjs_tooltips']['chartjs_customTooltips'] = array(
    '#type' => 'radios',
    '#title' => t('Custom Tool Tips'),
    '#options' => array(
      'true' => t('On'),
      'false' => t('Off'),
    ),
    '#default_value' => variable_get('chartjs_customTooltips', 'false'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipFillColor'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Fill Color'),
    '#default_value' => variable_get('chartjs_tooltipFillColor', 'rgba(0,0,0,0.8)'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipFontFamily'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Font Family'),
    '#default_value' => variable_get('chartjs_tooltipFontFamily', "'Helvetica Neue', 'Helvetica', 'Arial', sans-serif"),
  );
  $form['chartjs_tooltips']['chartjs_tooltipFontSize'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Font Size'),
    '#default_value' => variable_get('chartjs_tooltipFontSize', '14'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipFontStyle'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Font Style'),
    '#default_value' => variable_get('chartjs_tooltipFontStyle', 'normal'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipFontColor'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Font Color'),
    '#default_value' => variable_get('chartjs_tooltipFontColor', '#fff'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipTitleFontFamily'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Title Font Family'),
    '#default_value' => variable_get('chartjs_tooltipTitleFontFamily', "'Helvetica Neue', 'Helvetica', 'Arial', sans-serif"),
  );
  $form['chartjs_tooltips']['chartjs_tooltipTitleFontSize'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Title Font Size'),
    '#default_value' => variable_get('chartjs_tooltipTitleFontSize', '14'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipTitleFontStyle'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Title Font Style'),
    '#default_value' => variable_get('chartjs_tooltipTitleFontStyle', 'bold'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipTitleFontColor'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Title Font Color'),
    '#default_value' => variable_get('chartjs_tooltipTitleFontColor', '#fff'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipYPadding'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Y Padding'),
    '#default_value' => variable_get('chartjs_tooltipYPadding', '6'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipXPadding'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip X Padding'),
    '#default_value' => variable_get('chartjs_tooltipXPadding', '6'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipCaretSize'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Caret Size'),
    '#default_value' => variable_get('chartjs_tooltipCaretSize', '8'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipCornerRadius'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip Corner Radius'),
    '#default_value' => variable_get('chartjs_tooltipCornerRadius', '6'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipXOffset'] = array(
    '#type' => 'textfield',
    '#title' => t('Tool Tip X Offset'),
    '#default_value' => variable_get('chartjs_tooltipXOffset', '10'),
  );
  $form['chartjs_tooltips']['chartjs_tooltipTemplate'] = array(
    '#type' => 'textarea',
    '#title' => t('Tool Tip Template'),
    '#default_value' => variable_get('chartjs_tooltipTemplate', '<%if (label){%><%=label%>: <%}%><%= value %>'),
  );
  $form['chartjs_tooltips']['chartjs_multiTooltipTemplate'] = array(
    '#type' => 'textarea',
    '#title' => t('Multi Tool Tip Template'),
    '#default_value' => variable_get('chartjs_multiTooltipTemplate', '<%= value %>'),
  );

  return system_settings_form($form);
}
