<?php
/**
 * @file views-semantic-tabs.tpl.php
 * Default simple view template to display a list of rows as semantic tabs.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <dt><a href="#"><?php print $title; ?></a></dt>
<?php endif; ?>
  <dd>
  <?php foreach ($rows as $id => $row): ?>
      <?php print $row; ?>
  <?php endforeach; ?>
  </dd>