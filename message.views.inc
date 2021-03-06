<?php

/**
 * @file
 * Provide views data for message.module.
 */

/**
 * Implements hook_views_data().
 */
function message_views_data() {
  $data = array();

 // message table

  $data['message']['table']['group']  = t('Message');
  $data['message']['table']['base'] = array(
    'field' => 'mid',
    'title' => t('Message'),
    'help' => t('Logged messages.'),
  );
  $data['message']['table']['entity type'] = 'message';
  $data['message']['table']['wizard_id'] = 'message';

  // message field
  $data['message']['mid'] = array(
    'title' => t('Message ID'),
    'help' => t('The mid of a Message.'),
    'field' => array(
      'id' => 'numeric',
    ),
    'sort' => array(
      'id' => 'standard',
    ),
    'argument' => array(
      'id' => 'message_mid',
      'name field' => 'mid',
      'zero is null' => TRUE,
    ),
    'filter' => array(
      'title' => t('Message ID'),
      'help' => t('Filter by the message ID.'),
      'id' => 'mid',
      'numeric' => TRUE,
    ),
  );

  $data['message']['text'] = array(
    'title' => t('The message text'),
    'help' => t('The text of the message'),
    'field' => array(
      'id' => 'get_text',
      'real field' => 'mid',
    ),
    'sort' => array(
      'id' => 'standard',
    ),
  );

  $data['message']['created'] = array(
    'title' => t('Post date'),
    'help' => t('The date the content was posted.'),
    'field' => array(
      'id' => 'date',
    ),
    'sort' => array(
      'id' => 'date'
    ),
    'filter' => array(
      'id' => 'date',
    ),
  );

  $data['message']['type'] = array(
    'title' => t('Message type'),
    'help' => t('The label of the message type'),
    'field' => array(
      'id' => 'message_type',
    ),
    'sort' => array(
      'id' => 'standard',
    ),
    'filter' => array(
      'id' => 'bundle',
    ),
  );

  $data['message']['uid'] = array(
    'title' => t('Author uid'),
    'help' => t('The owner of the message. If you need more fields than the uid add the content: author relationship'),
    'relationship' => array(
      'title' => t('Message owner'),
      'help' => t('Relate the message to her owner'),
      'id' => 'standard',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('author'),
    ),
    'filter' => array(
      'id' => 'user',
    ),
    'argument' => array(
      'id' => 'numeric',
    ),
    'field' => array(
      'id' => 'user',
    ),
  );

  return $data;
}

/**
 * Implements hook_views_data_alter().
 */
function message_views_data_alter(&$data) {
  // todo: Fix later.
  return;
  $data['message']['message_bulk_form'] = array(
    'title' => t('Message operations bulk form'),
    'help' => t('Add a form element that lets you run operations on multiple messages.'),
    'field' => array(
      'id' => 'message_bulk_form',
    ),
  );
}
