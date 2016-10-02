#ifndef DISPAR_PROJECT_H
#define DISPAR_PROJECT_H

#include <QHash>
#include <QString>
#include <QStringList>

#include <memory>

/// This class represents a project (saved with extension .dispar).
/** It contains information about the binary, machine code modifications, custom tags, comments
    etc. */
class Project {
public:
  Project();
  ~Project();

  /// Load project from \p file.
  /** Returns \p nullptr if nonexistent or failed. */
  static std::shared_ptr<Project> load(const QString &file);

  /// Save project to \p file, if specified, otherwise save to \p file().
  bool save(const QString &file = QString());

  QString binary() const;
  void setBinary(const QString &file);

  QString file() const;

  /// Tags for a specified address.
  QStringList addressTags(quint64 address) const;

  /// Associates \p tag with \p address.
  /** Checks if tag is not taken already, too. */
  bool addAddressTag(const QString &tag, quint64 address);

private:
  QString binary_, file_;
  QHash<quint64, QStringList> addressTags_;
};

#endif // DISPAR_PROJECT_H
