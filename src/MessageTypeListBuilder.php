<?php

/**
 * @file
 * Contains \Drupal\message\MessageTypeListBuilder.
 */

namespace Drupal\message;

use Drupal\Core\Config\Entity\ConfigEntityListBuilder;
use Drupal\Core\Entity\EntityInterface;
use Drupal\Component\Utility\Xss;

/**
 * Defines a class to build a listing of message type entities.
 *
 * @see \Drupal\message\Entity\MessageType
 */
class MessageTypeListBuilder extends ConfigEntityListBuilder {

  /**
   * {@inheritdoc}
   */
  public function buildHeader() {
    $header['title'] = t('Name');
    $header['description'] = array(
      'data' => t('Description'),
      'class' => array(RESPONSIVE_PRIORITY_MEDIUM),
    );
    return $header + parent::buildHeader();
  }

  /**
   * {@inheritdoc}
   */
  public function buildRow(EntityInterface $entity) {
    $row['title'] = array(
      'data' => $this->getLabel($entity),
      'class' => array('menu-label'),
    );
    $row['description'] = Xss::filterAdmin($entity->description);
    return $row + parent::buildRow($entity);
  }

  /**
   * {@inheritdoc}
   */
  public function getDefaultOperations(EntityInterface $entity) {
    return array(
      'edit' => array(
        'title' => t('Edit'),
        'router_name' => 'message_type.edit',
        'weight' => 0,
      ) + $entity->urlInfo('edit-form')->toArray(),
      'delete' => array(
        'title' => t('Delete'),
        'router_name' => 'message_type.delete',
        'weight' => 1,
      ) + $entity->urlInfo('delete-form')->toArray(),
    );
  }
}
