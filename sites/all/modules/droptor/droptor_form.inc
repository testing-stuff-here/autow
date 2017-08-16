<?php

// $Id: droptor_form.inc,v 1.2.2.3 2010/08/19 14:36:57 urbanjustin Exp $ 

/**
 * @file
 * The Droptor bridge module
 * Droptor.com - Drupal site organization, monitoring, management and best practices
 *
 * For more information, see:
 * - http://www.droptor.com
 * - http://drupal.org/project/droptor
 */

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function droptor_settings() {
  $fssl = droptor_ssl_enabled() == 1 ? TRUE : FALSE;
  $feed_url = url('droptorfeed/' . variable_get('droptor_hash', ''), array('absolute' => TRUE));

  if (variable_get('droptor_ssl_feed', 0) == 1 && drupal_substr($feed_url, 0, 5) != 'https') {
    $feed_url = 'https' . drupal_substr($feed_url, 4, drupal_strlen($feed_url));
  }
  elseif (variable_get('droptor_ssl_feed', 0) == 0 && drupal_substr($feed_url, 0, 5) == 'https') {
    $feed_url = 'http' . drupal_substr($feed_url, 5, drupal_strlen($feed_url));
  }

  $output = l(t('Droptor'), 'http://www.droptor.com/', array('attributes' => array('title' => t('Drupal site organization, monitoring, management and best practices.'))));
  $output .= ' ' . t('is a profiling and best practices service for Drupal. This module feeds information to the Droptor.com web site (mostly about your installed modules and system variables).');
  $output .= ' ' . t('You can learn more about the module at') . ' ';
  $output .= l(t('our web site'), 'http://www.Droptor.com/support/#droptor-monitoring-module', array('attributes' => array('title' => t('Our support page')))) . '.';
  $output .= '<br /><br />' . t('To maintain security the feed URL that provides data to Droptor will only be provided if the secret hash is provided, the request comes from the correct domain and');
  $output .= ' ' . '<span style="' . (!$fssl ? 'text-decoration:line-through' : '') . '">' . t('the request comes over SSL') . '</span>' . 
    t((!$fssl ? t('(your site appears to not support SSL)') : '')  . ($fssl && variable_get('droptor_ssl_feed', 0) == 0 ? t(' (you need to enable SSL below)') : '')  . '.');
  $output .= '<br/><br/>' . t('You can read more how we secure the feed') . ' ' . l(t('in our FAQ'), 'http://www.droptor.com/support/#droptor-monitoring-module-security') . '.';
  $output .= t(' Your feed URL:') . '<br />' .  l($feed_url, $feed_url, array('attributes' => array('target' => '_blank', 'title' => t('You will not be able to see this if the domain is set correctly below.'))));

  $droptor_form = drupal_get_form('droptor_settings_form'); // call the form first, so that error msg dissappears after debug mode is disabled.

  if (variable_get('droptor_debug_mode', 0) == 1) {
    drupal_set_message(t('Debug mode is currently enabled. It is important to disable this mode for production use.'), 'error');
  }  

  return $output . drupal_render($droptor_form);
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function droptor_settings_form($form) {
  $fssl = droptor_ssl_enabled() == 1 ? TRUE : FALSE;
  $checkbox_text = $fssl ? 'Your site supports SSL. You should require the feed connect over SSL for security' 
     : 'Your site doesn\'t support SSL, so we can\'t encrypt the feed';

  $form['droptor_hash'] = array(
    '#type' => 'textfield', 
    '#title' => t('Hash key'), 
    '#default_value' => variable_get('droptor_hash', NULL), 
    '#size' => 50, 
    '#maxlength' => 50, 
    '#description' => t('A secret key you get from') . ' ' . l(t('Droptor.com'), 'http://www.Droptor.com/sites') 
      . '. ' . t('For') . ' ' . l(t('security reasons'), 'http://www.droptor.com/support/#droptor-monitoring-module-security')
      . '  ' . t('the feed won\'t be shown unless this key is provided. Register your site at Droptor.com to get this key.'), 
    '#required' => TRUE, 
  );

  $form['droptor_domain'] = array(
    '#type' => 'textfield', 
    '#title' => t('Allowed domain'), 
    '#default_value' => variable_get('droptor_domain', 'droptor.com'), 
    '#size' => 50, 
    '#maxlength' => 15, 
    '#description' => t('For security reasons, we limit the data feed by IP/domain name. Enter in droptor.com here or your IP (') .  $_SERVER['REMOTE_ADDR']  . t(') if you want to see what the feed looks like).'), 
    '#required' => TRUE, 
  );

  $form['droptor_ssl_feed'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Send feed over SSL'), 
    '#default_value' => variable_get('droptor_ssl_feed', $fssl ? 'checked' : ''), 
    '#disabled' => $fssl ? FALSE : TRUE, 
    '#description' => t($checkbox_text), 
    '#required' => FALSE, 
  );
  
  $form['droptor_memory_monitoring'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Enable memory monitoring'), 
    '#default_value' => variable_get('droptor_memory_monitoring', 0), 
    '#description' => droptor_has_memory_management() ?
  		t('When checked Droptor will capture the memory usage and page execution for every page request. ' . l('More information', 'http://www.droptor.com/support#memory-monitoring') . '.') :
  		t('Your version of PHP does not support this feature. You need at least PHP 5.2.'), 
    '#disabled' => droptor_has_memory_management() ? FALSE : TRUE,
    '#required' => FALSE, 
  );

  $form['droptor_debug_mode'] = array(
    '#type' => 'checkbox', 
    '#title' => t('Enable debug mode.'), 
    '#default_value' => variable_get('droptor_debug_mode', ''), 
    '#description' => t('This returns additional data to Droptor.com that is helpful with troubleshooting connectivity issues. It is important to disable this mode for production use.'), 
    '#required' => FALSE, 
  );

  $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => t('Save'), 
  );

  return $form;
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function droptor_settings_form_validate(&$form, &$form_state) {
  if (drupal_strlen(trim($form_state['values']['droptor_hash'])) != 40) {
    form_set_error('', t('Please enter a hash value. You can get one from Droptor.com.'));
  }
}

/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function droptor_settings_form_submit(&$form, &$form_state) {
  variable_set('droptor_hash', $form_state['values']['droptor_hash']);
  variable_set('droptor_domain', $form_state['values']['droptor_domain']);
  variable_set('droptor_ssl_feed', $form_state['values']['droptor_ssl_feed']);
  variable_set('droptor_memory_monitoring', $form_state['values']['droptor_memory_monitoring']);
  variable_set('droptor_debug_mode', $form_state['values']['droptor_debug_mode']);
  drupal_set_message(t('Settings saved. Now return to') . ' ' . l(t('Droptor.com'), 'http://www.Droptor.com/sites') . ' ' . t('and run a scan!'));
}

/**
 * @package     isemail
 * @author      Dominic Sayers <dominic_sayers@hotmail.com>
 * @copyright   2009 Dominic Sayers
 * @license     http://www.opensource.org/licenses/bsd-license.php BSD License
 * @link        http://www.dominicsayers.com/isemail
 * @version     1.16 - Added optional diagnosis codes(amended all lines with a return statement)
 */

/*
 Copyright(c) 2008-2010, Dominic Sayers
 All rights reserved.

 Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:

 * Redistributions of source code must retain the above copyright notice, this
 list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
 this list of conditions and the following disclaimer in the documentation
 and/or other materials provided with the distribution.
 * Neither the name of Dominic Sayers nor the names of its contributors may be
 used to endorse or promote products derived from this software without
 specific prior written permission.

 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* .
 require_module 'standard';
 require_module 'pcre';
 . */
/* .mixed. */
/**
 * @todo Please document this function.
 * @see http://drupal.org/node/1354
 */
function droptor_is_email(/* .string. */ $email, $check_dns = FALSE, $diagnose = FALSE) {
  // Check that $email is a valid address. Read the following RFCs to understand the constraints:
  //     (http://tools.ietf.org/html/rfc5322)
  //     (http://tools.ietf.org/html/rfc3696)
  //     (http://tools.ietf.org/html/rfc5321)
  //     (http://tools.ietf.org/html/rfc4291#section-2.2)
  //     (http://tools.ietf.org/html/rfc1123#section-2.1)

  if (!defined('ISEMAIL_VALID')) {
    define('ISEMAIL_VALID'                  , 0);
    define('ISEMAIL_TOOLONG'                , 1);
    define('ISEMAIL_NOAT'                   , 2);
    define('ISEMAIL_NOLOCALPART'            , 3);
    define('ISEMAIL_NODOMAIN'               , 4);
    define('ISEMAIL_ZEROLENGTHELEMENT'      , 5);
    define('ISEMAIL_BADCOMMENT_START'       , 6);
    define('ISEMAIL_BADCOMMENT_END'         , 7);
    define('ISEMAIL_UNESCAPEDDELIM'         , 8);
    define('ISEMAIL_EMPTYELEMENT'           , 9);
    define('ISEMAIL_UNESCAPEDSPECIAL'       , 10);
    define('ISEMAIL_LOCALTOOLONG'           , 11);
    define('ISEMAIL_IPV4BADPREFIX'          , 12);
    define('ISEMAIL_IPV6BADPREFIXMIXED'     , 13);
    define('ISEMAIL_IPV6BADPREFIX'          , 14);
    define('ISEMAIL_IPV6GROUPCOUNT'         , 15);
    define('ISEMAIL_IPV6DOUBLEDOUBLECOLON'  , 16);
    define('ISEMAIL_IPV6BADCHAR'            , 17);
    define('ISEMAIL_IPV6TOOMANYGROUPS'      , 18);
    define('ISEMAIL_TLD'                    , 19);
    define('ISEMAIL_DOMAINEMPTYELEMENT'     , 20);
    define('ISEMAIL_DOMAINELEMENTTOOLONG'   , 21);
    define('ISEMAIL_DOMAINBADCHAR'          , 22);
    define('ISEMAIL_DOMAINTOOLONG'          , 23);
    define('ISEMAIL_TLDNUMERIC'             , 24);
    define('ISEMAIL_DOMAINNOTFOUND'         , 25);
    define('ISEMAIL_NOTDEFINED'             , 99);
  }

  // the upper limit on address lengths should normally be considered to be 256
  //     (http://www.rfc-editor.org/errata_search.php?rfc=3696)
  //      NB I think John Klensin is misreading RFC 5321 and the the limit should actually be 254
  //      However, I will stick to the published number until it is changed.
  //
  // The maximum total length of a reverse-path or forward-path is 256
  // characters(including the punctuation and element separators)
  //     (http://tools.ietf.org/html/rfc5321#section-4.5.3.1.3)
  $email_length = drupal_strlen($email);
  if ($email_length > 256) {
    return $diagnose ? ISEMAIL_TOOLONG       : FALSE;
  } // Too long

  // Contemporary email addresses consist of a "local part" separated from
  // a "domain part"(a fully-qualified domain name) by an at-sign("@").
  //     (http://tools.ietf.org/html/rfc3696#section-3)
  $at_index = strrpos($email, '@');

  if ($at_index === FALSE) {
    return $diagnose ? ISEMAIL_NOAT          : FALSE;
  } // No at-sign
  if ($at_index === 0) {
    return $diagnose ? ISEMAIL_NOLOCALPART   : FALSE;
  } // No local part
  if ($at_index === $email_length - 1) {
    return $diagnose ? ISEMAIL_NODOMAIN      : FALSE;
  } // No domain part
  // revision 1.14: Length test bug suggested by Andrew Campbell of Gloucester, MA

  // Sanitize comments
  // - remove nested comments, quotes and dots in comments
  // - remove parentheses and dots from quoted strings
  $brace_depth     = 0;
  $in_quote        = FALSE;
  $escape_this_char = FALSE;

  for ($i = 0; $i < $email_length; ++$i) {
    $char = $email[$i];
    $replace_char = FALSE;

    if ($char === '\\') {
      $escape_this_char = !$escape_this_char; // Escape the next character?
    }
    else {
      switch ($char) {
        case '(':
          if ($escape_this_char) {
            $replace_char = TRUE;
          }
          else {
            if ($in_quote) {
              $replace_char = TRUE;
            }
            else {
              if ($brace_depth++ > 0) {
                $replace_char = TRUE;
              } // Increment brace depth
            }
          }
          break;

        case ')':
          if ($escape_this_char) {
            $replace_char = TRUE;
          }
          else {
            if ($in_quote) {
              $replace_char = TRUE;
            }
            else {
              if (--$brace_depth > 0) {
                $replace_char = TRUE;
              } // Decrement brace depth
              if ($brace_depth < 0) {
                $brace_depth = 0;
              }
            }
          }
          break;

        case '"':
          if ($escape_this_char) {
            $replace_char = TRUE;
          }
          else {
            if ($brace_depth === 0) {
              $in_quote = !$in_quote; // Are we inside a quoted string?
            }
            else {
              $replace_char = TRUE;
            }
          }
          break;

        case '.': // Dots don't help us either
          if ($escape_this_char) {
            $replace_char = TRUE;
          }
          else {
            if ($brace_depth > 0) {
              $replace_char = TRUE;
            }
          }
          break;

        default:
      }

      $escape_this_char = FALSE;
      //                      if ($replace_char) $email[$i] = 'x';     // Replace the offending character with something harmless
      // revision 1.12: Line above replaced because PHPLint doesn't like that syntax

      if ($replace_char) {
        $email = (string) substr_replace($email, 'x', $i, 1);
      } // Replace the offending character with something harmless
    }
  }

  $local_part      = drupal_substr($email, 0, $at_index);
  $domain         = drupal_substr($email, $at_index + 1);
  $fws            = "(?:(?:(?:[ \\t]*(?:\\r\\n))?[ \\t]+)|(?:[ \\t]+(?:(?:\\r\\n)[ \\t]+)*))"; // Folding white space
  // Let's check the local part for RFC compliance...
  //
  // local-part      =       dot-atom / quoted-string / obs-local-part
  // obs-local-part  =       word *("." word)
  //     (http://tools.ietf.org/html/rfc5322#section-3.4.1)
  //
  // Problem: need to distinguish between "first.last" and "first"."last"
  //(i.e. one element or two). And I suck at regexes.
  $dot_array       = /* .(array[int]string) . */ preg_split('/\\.(?=(?:[^\\"]*\\"[^\\"]*\\")*(?![^\\"]*\\"))/m', $local_part);
  $part_length     = 0;

  foreach ($dot_array as $element) {
    // Remove any leading or trailing FWS
    $element        = preg_replace("/^$fws|$fws\$/", '', $element);
    $element_length  = drupal_strlen($element);

    if ($element_length === 0) {
      return $diagnose ? ISEMAIL_ZEROLENGTHELEMENT : FALSE;
    } // Can't have empty element(consecutive dots or dots at the start or end)
    // revision 1.15: Speed up the test and get rid of "unitialized string offset" notices from PHP

    // We need to remove any valid comments(i.e. those at the start or end of the element)
    if ($element[0] === '(') {
      $index_brace = strpos($element, ')');
      if ($index_brace !== FALSE) {
        if (preg_match('/(?<!\\\\)[\\(\\)]/', drupal_substr($element, 1, $index_brace - 1)) > 0) {
          return $diagnose ? ISEMAIL_BADCOMMENT_START      : FALSE; // Illegal characters in comment
        }
        $element        = drupal_substr($element, $index_brace + 1, $element_length - $index_brace - 1);
        $element_length  = drupal_strlen($element);
      }
    }

    if ($element[$element_length - 1] === ')') {
      $index_brace = strrpos($element, '(');
      if ($index_brace !== FALSE) {
        if (preg_match('/(?<!\\\\)(?:[\\(\\)])/', drupal_substr($element, $index_brace + 1, $element_length - $index_brace - 2)) > 0) {
          return $diagnose ? ISEMAIL_BADCOMMENT_END        : FALSE; // Illegal characters in comment
        }
        $element        = drupal_substr($element, 0, $index_brace);
        $element_length  = drupal_strlen($element);
      }
    }


    // Remove any leading or trailing FWS around the element(inside any comments)
    $element = preg_replace("/^$fws|$fws\$/", '', $element);

    // What's left counts towards the maximum length for this part
    if ($part_length > 0) {
      $part_length++;
    } // for the dot
    $part_length += drupal_strlen($element);

    // Each dot-delimited component can be an atom or a quoted string
    //(because of the obs-local-part provision)
    if (preg_match('/^"(?:.)*"$/s', $element) > 0) {
      // Quoted-string tests:
      //
      // Remove any FWS
      $element = preg_replace("/(?<!\\\\)$fws/", '', $element);
      // My regex skillz aren't up to distinguishing between \" \\" \\\" \\\\" etc.
      // So remove all \\ from the string first...
      $element = preg_replace('/\\\\\\\\/', ' ', $element);
      if (preg_match('/(?<!\\\\|^)["\\r\\n\\x00](?!$)|\\\\"$|""/', $element) > 0) {
        return $diagnose ? ISEMAIL_UNESCAPEDDELIM        : FALSE;
      } // ", CR, LF and NUL must be escaped, "" is too short
    }
    else {
      // Unquoted string tests:
      //
      // Period(".") may...appear, but may not be used to start or end the
      // local part, nor may two or more consecutive periods appear.
      //     (http://tools.ietf.org/html/rfc3696#section-3)
      //
      // A zero-length element implies a period at the beginning or end of the
      // local part, or two periods together. Either way it's not allowed.
      if ($element === '') {
        return $diagnose ? ISEMAIL_EMPTYELEMENT : FALSE;
      } // Dots in wrong place

      // Any ASCII graphic(printing) character other than the
      // at-sign("@"), backslash, double quote, comma, or square brackets may
      // appear without quoting.  If any of that list of excluded characters
      // are to appear, they must be quoted
      //     (http://tools.ietf.org/html/rfc3696#section-3)
      //
      // Any excluded characters? i.e. 0x00-0x20,(, ), <, >, [, ], :, ;, @, \, comma, period, "
      if (preg_match('/[\\x00-\\x20\\(\\)<>\\[\\]:;@\\\\, \\."]/', $element) > 0) {
        return $diagnose ? ISEMAIL_UNESCAPEDSPECIAL      : FALSE;
      } // These characters must be in a quoted string
    }
  }

  if ($part_length > 64) {
    return $diagnose ? ISEMAIL_LOCALTOOLONG    : FALSE;
  } // Local part must be 64 characters or less

  // Now let's check the domain part...

  // The domain name can also be replaced by an IP address in square brackets
  //     (http://tools.ietf.org/html/rfc3696#section-3)
  //     (http://tools.ietf.org/html/rfc5321#section-4.1.3)
  //     (http://tools.ietf.org/html/rfc4291#section-2.2)
  if (preg_match('/^\\[(.)+]$/', $domain) === 1) {
    // It's an address-literal
    $address_literal = drupal_substr($domain, 1, drupal_strlen($domain) - 2);
    $matches_ip       = array();

    // Extract IPv4 part from the end of the address-literal(if there is one)
    if (preg_match('/\\b(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/', $address_literal, $matches_ip ) > 0) {
      $index = strrpos($address_literal, $matches_ip[0]);

      if ($index === 0) {
        // Nothing there except a valid IPv4 address, so...
        return $diagnose ? ISEMAIL_VALID : TRUE;
      }
      else {
        // Assume it's an attempt at a mixed address(IPv6 + IPv4)
        if ($address_literal[$index - 1] !== ':') {
          return $diagnose ? ISEMAIL_IPV4BADPREFIX         : FALSE;
        } // Character preceding IPv4 address must be ':'
        if (drupal_substr($address_literal, 0, 5) !== 'IPv6:') {
          return $diagnose ? ISEMAIL_IPV6BADPREFIXMIXED    : FALSE;
        } // RFC5321 section 4.1.3

        $ipv6           = drupal_substr($address_literal, 5, ($index === 7) ? 2 : $index - 6);
        $group_max       = 6;
      }
    }
    else {
      // It must be an attempt at pure IPv6
      if (drupal_substr($address_literal, 0, 5) !== 'IPv6:') {
        return $diagnose ? ISEMAIL_IPV6BADPREFIX         : FALSE;
      } // RFC5321 section 4.1.3
      $ipv6 = drupal_substr($address_literal, 5);
      $group_max = 8;
    }

    $group_count     = preg_match_all('/^[0-9a-fA-F]{0, 4}|\\:[0-9a-fA-F]{0, 4}|(.)/', $ipv6, $matches_ip );
    $index          = strpos($ipv6, '::');

    if ($index === FALSE) {
      // We need exactly the right number of groups
      if ($group_count !== $group_max) {
        return $diagnose ? ISEMAIL_IPV6GROUPCOUNT        : FALSE;
      } // RFC5321 section 4.1.3
    }
    else {
      if ($index !== strrpos($ipv6, '::')) {
        return $diagnose ? ISEMAIL_IPV6DOUBLEDOUBLECOLON : FALSE;
      } // More than one '::'
      $group_max = ($index === 0 || $index === (drupal_strlen($ipv6) - 2)) ? $group_max : $group_max - 1;
      if ($group_count > $group_max) {
        return $diagnose ? ISEMAIL_IPV6TOOMANYGROUPS     : FALSE;
      } // Too many IPv6 groups in address
    }

    // Check for unmatched characters
    array_multisort($matches_ip[1], SORT_DESC);
    if ($matches_ip[1][0] !== '') {
      return $diagnose ? ISEMAIL_IPV6BADCHAR           : FALSE;
    } // Illegal characters in address

    // It's a valid IPv6 address, so...
    return $diagnose ? ISEMAIL_VALID : TRUE;
  }
  else {
    // It's a domain name...

    // The syntax of a legal Internet host name was specified in RFC-952
    // One aspect of host name syntax is hereby changed: the
    // restriction on the first character is relaxed to allow either a
    // letter or a digit.
    //     (http://tools.ietf.org/html/rfc1123#section-2.1)
    //
    // NB RFC 1123 updates RFC 1035, but this is not currently apparent from reading RFC 1035.
    //
    // Most common applications, including email and the Web, will generally not
    // permit...escaped strings
    //     (http://tools.ietf.org/html/rfc3696#section-2)
    //
    // the better strategy has now become to make the "at least one period" test, 
    // to verify LDH conformance(including verification that the apparent TLD name
    // is not all-numeric)
    //     (http://tools.ietf.org/html/rfc3696#section-2)
    //
    // Characters outside the set of alphabetic characters, digits, and hyphen MUST NOT appear in domain name
    // labels for SMTP clients or servers
    //     (http://tools.ietf.org/html/rfc5321#section-4.1.2)
    //
    // RFC5321 precludes the use of a trailing dot in a domain name for SMTP purposes
    //     (http://tools.ietf.org/html/rfc5321#section-4.1.2)
    $dot_array       = /* .(array[int]string) . */ preg_split('/\\.(?=(?:[^\\"]*\\"[^\\"]*\\")*(?![^\\"]*\\"))/m', $domain);
    $part_length     = 0;
    $element        = ''; // Since we use $element after the foreach loop let's make sure it has a value
    // revision 1.13: Line above added because PHPLint now checks for Definitely Assigned Variables

    if (count($dot_array) === 1) {
      return $diagnose ? ISEMAIL_TLD   : FALSE;
    } // Mail host can't be a TLD(cite? What about localhost?)

    foreach ($dot_array as $element) {
      // Remove any leading or trailing FWS
      $element        = preg_replace("/^$fws|$fws\$/", '', $element);
      $element_length  = drupal_strlen($element);

      // Each dot-delimited component must be of type atext
      // A zero-length element implies a period at the beginning or end of the
      // local part, or two periods together. Either way it's not allowed.
      if ($element_length === 0) {
        return $diagnose ? ISEMAIL_DOMAINEMPTYELEMENT    : FALSE;
      } // Dots in wrong place
      // revision 1.15: Speed up the test and get rid of "unitialized string offset" notices from PHP

      // Then we need to remove all valid comments(i.e. those at the start or end of the element
      if ($element[0] === '(') {
        $index_brace = strpos($element, ')');
        if ($index_brace !== FALSE) {
          if (preg_match('/(?<!\\\\)[\\(\\)]/', drupal_substr($element, 1, $index_brace - 1)) > 0) {
            return $diagnose ? ISEMAIL_BADCOMMENTSTART       : FALSE; // Illegal characters in comment
          }
          $element        = drupal_substr($element, $index_brace + 1, $element_length - $index_brace - 1);
          $element_length  = drupal_strlen($element);
        }
      }

      if ($element[$element_length - 1] === ')') {
        $index_brace = strrpos($element, '(');
        if ($index_brace !== FALSE) {
          if (preg_match('/(?<!\\\\)(?:[\\(\\)])/', drupal_substr($element, $index_brace + 1, $element_length - $index_brace - 2)) > 0) {
            return $diagnose ? ISEMAIL_BADCOMMENTEND         : FALSE;
          } // Illegal characters in comment

          $element        = drupal_substr($element, 0, $index_brace);
          $element_length  = drupal_strlen($element);
        }
      }

      // Remove any leading or trailing FWS around the element(inside any comments)
      $element = preg_replace("/^$fws|$fws\$/", '', $element);

      // What's left counts towards the maximum length for this part
      if ($part_length > 0) {
        $part_length++;
      } // for the dot
      $part_length += drupal_strlen($element);

      // The DNS defines domain name syntax very generally -- a
      // string of labels each containing up to 63 8-bit octets, 
      // separated by dots, and with a maximum total of 255
      // octets.
      //     (http://tools.ietf.org/html/rfc1123#section-6.1.3.5)
      if ($element_length > 63) {
        return $diagnose ? ISEMAIL_DOMAINELEMENTTOOLONG : FALSE;
      } // Label must be 63 characters or less

      // Any ASCII graphic(printing) character other than the
      // at-sign("@"), backslash, double quote, comma, or square brackets may
      // appear without quoting.  If any of that list of excluded characters
      // are to appear, they must be quoted
      //     (http://tools.ietf.org/html/rfc3696#section-3)
      //
      // If the hyphen is used, it is not permitted to appear at
      // either the beginning or end of a label.
      //     (http://tools.ietf.org/html/rfc3696#section-2)
      //
      // Any excluded characters? i.e. 0x00-0x20,(, ), <, >, [, ], :, ;, @, \, comma, period, "
      if (preg_match('/[\\x00-\\x20\\(\\)<>\\[\\]:;@\\\\, \\."]|^-|-$/', $element) > 0) {
        return $diagnose ? ISEMAIL_DOMAINBADCHAR         : FALSE;
      }
    }

    if ($part_length > 255) {
      return $diagnose ? ISEMAIL_DOMAINTOOLONG         : FALSE;
    } // Domain part must be 255 characters or less(http://tools.ietf.org/html/rfc1123#section-6.1.3.5)

    if (preg_match('/^[0-9]+$/', $element) > 0) {
      return $diagnose ? ISEMAIL_TLDNUMERIC            : FALSE;
    } // TLD can't be all-numeric(http://www.apps.ietf.org/rfc/rfc3696.html#sec-2)

    // Check DNS?
    if ($check_dns && function_exists('checkdnsrr')) {
      if (!(checkdnsrr($domain, 'A') || checkdnsrr($domain, 'MX'))) {
        return $diagnose ? ISEMAIL_DOMAINNOTFOUND        : FALSE; // Domain doesn't actually exist
      }
    }
  }


  // Eliminate all other factors, and the one which remains must be the truth.
  //     (Sherlock Holmes, The Sign of Four)
  return $diagnose ? ISEMAIL_VALID : TRUE;
}
